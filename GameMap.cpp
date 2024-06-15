#include "include/GameMap.h"
#include "include/Item.h"
#include "include/MissionScore.h"
#include <iostream>
#include <stdlib.h>
#include <time.h> 
#include <ncurses.h>


GameMap::GameMap(int width, int height, int* stage) : width(width), height(height), stage(stage), missionScore() {
    mapArray = new int*[height];
    for (int i = 0; i < height; i++) {
        mapArray[i] = new int[width];
    }
    missionScore.MissionList(stage);
    gates = new int[4]; 
    initMap(); // 스테이지 초기화
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
            } else if (y == 0 || y == height - 1 || x == 0 || x == width - 1) {
                mapArray[y][x] = 1; // 벽
            } else {
                mapArray[y][x] = 0; // 빈공간
            }
        }
    }

    switch (*stage) {
        case 1:
            for (int y = 5; y < 16; y++) {
                mapArray[y][24] = 1; // 장애물
            }
            for (int y = 5; y < 16; y++) {
                mapArray[y][25] = 1; // 장애물
            }
            break;
        case 2:
            for (int y = 5; y < 15; y++) {
                mapArray[y][24] = 1; // 장애물
            }
            for (int y = 5; y < 15; y++) {
                mapArray[y][25] = 1; // 장애물
            }
            for (int x = 10; x < 38; x++) {
                mapArray[5][x] = 1; // 장애물
            }
            for (int x = 10; x < 38; x++) {
                mapArray[15][x] = 1; // 장애물
            }
            break;
        case 3:
            for (int y = 3; y < 6; y++) {
                mapArray[y][10] = 1; // 장애물
            }
            for (int y = 9; y < 12; y++) {
                mapArray[y][20] = 1; // 장애물
            }
            for (int y = 16; y < 19; y++) {
                mapArray[y][30] = 1; // 장애물
            }
            break;
        case 4:
            for (int y = 13; y < 16; y++) {
                mapArray[y][24] = 1; // 장애물
            }
            for (int y = 13; y < 16; y++) {
                mapArray[y][25] = 1; // 장애물
            }
            for (int y = 3; y < 6; y++) {
                mapArray[y][24] = 1; // 장애물
            }
            for (int y = 3; y < 6; y++) {
                mapArray[y][25] = 1; // 장애물
            }
            for (int x = 13; x < 19; x++) {
                mapArray[7][x] = 1; // 장애물
            }
            for (int x = 33; x < 39; x++) {
                mapArray[7][x] = 1; // 장애물
            }
            for (int x = 13; x < 19; x++) {
                mapArray[11][x] = 1; // 장애물
            }
            for (int x = 33; x < 39; x++) {
                mapArray[11][x] = 1; // 장애물
            }
            break;

        default:
            break;
    }
}

void GameMap::TitleMap() const {
                
    mvwprintw(stdscr, 0, width/2, " _____         _          _____   ");
    mvwprintw(stdscr, 1, width/2, "|   __|___ ___| |_ ___   |   __|___ _____ ___ ");
    mvwprintw(stdscr, 2, width/2, "|__   |   | .'| '_| -_|  |  |  | .'|     | -_|");
    mvwprintw(stdscr, 3, width/2, "|_____|_|_|__,|_,_|___|  |_____|__,|_|_|_|___|");

    mvwprintw(stdscr, 7, width/2+6, "<Press Enterkey to Start Game>");

    refresh();
                                            
};

void GameMap::GameOverMap() const {
                                                  
    mvwprintw(stdscr, 0, width/2-2, " _____             _               ");
    mvwprintw(stdscr, 1, width/2-2, "|     |___ ___ ___| |_ ___ ___ ___ ");
    mvwprintw(stdscr, 2, width/2-2, "|   --|  _| -_| .'|  _| . |  _|_ -|");
    mvwprintw(stdscr, 3, width/2-2, "|_____|_| |___|__,|_| |___|_| |___|");

                                   

    mvprintw(7, width/2+3, "JeongHyunjoo[jhj04]");
    mvprintw(8, width/2+3, "KimSehyun[SeHyun-Kim04]");
    mvprintw(9, width/2+3, "Choahyoung[twnbay]");
    mvprintw(10, width/2+3, "CzorapinskaWeronika[seennothing]");

    refresh();
                                            
};

void GameMap::WaitingMap() const {

    clear();
                                                  
    mvprintw(height/2, width/2-2, "stage %d", *stage);

    mvprintw(height/2+2, width/2-2, "Press Enterkey");


    refresh();
                                            
};

void GameMap::nextStage() {
    if (*stage <= 4
    && missionScore.getNowGrowth() >= missionScore.getMissionGrowth()
    && missionScore.getNowLength() >= missionScore.getMissionLength() 
    && missionScore.getNowPoison() >= missionScore.getMissionPoison()
    // && missionScore.getMissionGates() == getGates()
    ){
        (*stage+=1);

        missionScore.MissionList(stage);
        WaitingMap();

        int press;
        while(true){
            press = getch();
            if(press == 10){
                clear();
                break;
            }
        }
        clear();
        refresh();
        initMap();
        printMap();
        displayState();
        displayMissions();

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
                case 5:
                	attron(COLOR_PAIR(1));
                	mvprintw(y, x, "G");
                	attroff(COLOR_PAIR(1));
                	break;
                	// !! GROWTH 아이템
                case 6: 
                	attron(COLOR_PAIR(2));
                	mvprintw(y, x, "P");
                	attroff(COLOR_PAIR(2));
                	break;
                	 // !!POISON 아이템
                case 7: mvprintw(y, x, "."); break; // gate
                case 8:
                	attron(COLOR_PAIR(3));
                	mvprintw(y, x, "R");
                	attroff(COLOR_PAIR(3));
                	break;
                	// RANDOM 아이템
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

void GameMap::mGrowth() {
    missionScore.setNowGrowth(missionScore.getNowGrowth());

}

void GameMap::incrementGrowth() {
    missionScore.setNowGrowth(missionScore.getNowGrowth() + 1);

}

void GameMap::incrementPoison() {
    missionScore.setNowPoison(missionScore.getNowPoison() + 1);
}

void GameMap::incrementLength(int itemType) {

    switch (itemType){
    case 5:
        missionScore.setNowLength(missionScore.getNowLength() + 1);
        break;
    case 6:
        missionScore.setNowLength(missionScore.getNowLength() - 1);
        break;
        
    default:
        break;
    }
}
void GameMap::displayMissions() const {
    int xOffset = width + 4;
    int missionMapWidth = 20;
    int missionMapHeight = 6;

    for (int y = 5; y <= 5 + missionMapHeight; y++) {
        for (int x = xOffset; x <= 5 + missionMapWidth; x++ ){
            if (y == 5 || y == 5 + missionMapHeight) {
                mvprintw(y, x, "-");
            } else if (x == xOffset || x == 5 + missionMapWidth) {
                mvprintw(y, x, "|");
            } else {
                mvprintw(y, x, " ");
            }
        }
    }

    mvprintw(2, xOffset + 8, "Missions");
    mvprintw(3, xOffset + 8, "Stage : %d", *stage);
    mvprintw(5, xOffset + 1, " Growth: %d", missionScore.getMissionGrowth());
    mvprintw(6, xOffset + 1, " Poison: %d", missionScore.getMissionPoison());
    mvprintw(7, xOffset + 1, " Length: %d", missionScore.getMissionLength());
    mvprintw(8, xOffset+1, " Gates: %d", missionScore.getMissionGates());

}

void GameMap::displayState() const {
    int xOffset = width + 4;
    int missionMapWidth = 20;
    int missionMapHeight = 6;

    for (int y = 9 ; y <= 9 + missionMapHeight ; y++) {
        for (int x = xOffset; x <= xOffset + missionMapWidth; x++ ){
            if (y == 9 || y == 9 + missionMapHeight) {
                mvprintw(y, x, "-");
            } else if (x == xOffset || x == xOffset + missionMapWidth) {
                mvprintw(y, x, "|");
            } else {
                mvprintw(y, x, " ");
            }
        }
    }
    mvprintw(10, xOffset+5, "ScoreBoard");
    mvprintw(11, xOffset+1, " Growth: %d", missionScore.getNowGrowth());
    mvprintw(12, xOffset+1, " Poison: %d", missionScore.getNowPoison());
    mvprintw(13, xOffset+1, " Length: %d", missionScore.getNowLength());
    // mvprintw(14, xOffset+1, " Gates: %p (%s)", (void*)&gates, gatesuccess ? "O" :"X");
    mvprintw(14, xOffset+1, " Gates: %d", missionScore.getNowLength());


}
