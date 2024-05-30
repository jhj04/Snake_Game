#include <iostream>
#include <stdlib.h>
#include <time.h> 
#include "include/GameMap.h"

using namespace std;


GameMap::GameMap(int width, int height) : width(width), height(height) {
    mapArray = new int*[height];
    for (int i = 0; i < height; i++) {
        mapArray[i] = new int[width];
    }
    gates = new int[4]; 
    initMap();
}

GameMap::~GameMap() {
    for (int i = 0; i < height; i++) {
        delete[] mapArray[i];
    }
    delete[] mapArray;
    delete[] gates; 
}

void GameMap::initMap() {
    createGate();
    int x1 = gates[0], y1 = gates[1], x2 = gates[2], y2 = gates[3];

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if ((y == y1 && x == x1) || (y == y2 && x == x2)){
                mapArray[y][x] = 7; //gate
            } 
            else if ((y == 0 && (x == 0 || x == width - 1)) || (y == height - 1 && (x == 0 || x == width - 1))) {
                mapArray[y][x] = 2; // 코너
            } 
            else if (y == 0 || y == height - 1 || x == 0 || x == width - 1) {
                mapArray[y][x] = 1; // 벽
            }
            else {
                mapArray[y][x] = 0; // 빈공간
            }
        }
    }
}

void GameMap::printMap() const {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            switch (mapArray[y][x]) {
                case 0: mvprintw(y, x, " "); break; // 빈공간
                case 1: mvprintw(y, x, "#"); break; // 벽
                case 2: mvprintw(y, x, "X"); break; // 코너
                case 3: mvprintw(y, x, "H"); break; // 뱀 Head
                case 4: mvprintw(y, x, "o"); break; // 뱀 Body
                case 7: mvprintw(y, x, "."); break; // gate
                default: mvprintw(y, x, "E");       // 오류
            }
        }
    }
}

void GameMap::createGate() {
    int width = getWidth();
    int height = getHeight();

    srand (time(NULL));
    int x1, x2, y1, y2;

    int side = rand() % 2;

    if (side == 1){
        x1 = rand() % (width - 4) + 2;
        x2 = rand() % (width - 4) + 2;
        y1 = 0;
        y2 = height - 1;
    }

    else{
        y1 = rand() % (height - 4) + 2;
        y2 = rand() % (height - 4) + 2;
        x1 = 0;
        x2 = width - 1;
    }

    gates[0] = x1;
    gates[1] = y1;
    gates[2] = x2;
    gates[3] = y2;
}

int* GameMap::getGates() const {
    return gates;
}

int GameMap::getWidth() const {
    return width;
}

int GameMap::getHeight() const {
    return height;
}

int GameMap::getMap(int x, int y) const {
    return mapArray[y][x];
}

void GameMap::setMap(int x, int y, int item) {
    mapArray[y][x] = item;
}


