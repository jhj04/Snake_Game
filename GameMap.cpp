#include "include/GameMap.h"

GameMap::GameMap(int width, int height) : width(width), height(height) {
    mapArray = new int*[height];
    for (int i = 0; i < height; i++) {
        mapArray[i] = new int[width];
    }
    initMap();
}

GameMap::~GameMap() {
    for (int i = 0; i < height; i++) {
        delete[] mapArray[i];
    }
    delete[] mapArray;
}

void GameMap::initMap() {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if ((y == 0 && (x == 0 || x == width - 1)) || (y == height - 1 && (x == 0 || x == width - 1))) {
                mapArray[y][x] = 2; // 코너
            } else if (y == 0 || y == height - 1 || x == 0 || x == width - 1) {
                mapArray[y][x] = 1; // 벽
            } else {
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
                case 5: mvprintw(y, x, "G"); break; // !! GROWTH 아이템
                case 6: mvprintw(y, x, "P"); break; // !!POISON 아이템
                default: mvprintw(y, x, "E");       // 오류
            }
        }
    }
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
