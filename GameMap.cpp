#include "include/GameMap.h"
#include "include/Item.h"
#include <ncurses.h>

GameMap::GameMap(int width, int height, int stage) 
: width(width), height(height), stage(stage){
    mapArray = new int*[height];
    for (int i = 0; i < height; i++) {
        mapArray[i] = new int[width];
    }
    missionScore.MissionList(stage);
    initMap(); // 스테이지 초기화
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

        switch (stage) {
        case 1:
            for (int y = 5; y < 7; y++) {
                mapArray[y][25] = 1; // 장애물
            }
            break;
        case 2:
            for (int y = 9; y < 11; y++) {
                mapArray[y][25] = 1; // 장애물
            }
            break;
        case 3:
            for (int y = 12; y < 15; y++) {
                mapArray[y][25] = 1; // 장애물
            }
            break;
        case 4:
            for (int y = 16; y < 19; y++) {
                mapArray[y][25] = 1; // 장애물
            }
            break;
        default:
            break;
    }
}

void GameMap::nextStage() {
    stage++;
    initMap(); // 새로운 스테이지 초기화
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

void GameMap::mGrowth() {
    missionScore.setMissionGrowth(missionScore.getMGrowth());

}

void GameMap::incrementGrowth() {
    missionScore.setMissionGrowth(missionScore.getMissionGrowth() + 1);

}

void GameMap::incrementPoison() {
    missionScore.setMissionPoison(missionScore.getMissionPoison() + 1);
}

void GameMap::incrementLength(int itemType) {
    switch (itemType){
    case 5:
        missionScore.setMissionLength(missionScore.getMissionLength() + 1);
        break;
    case 6:
        missionScore.setMissionLength(missionScore.getMissionLength() - 1);
        break;
    default:
        break;
    }
}
void GameMap::displayMissions() const {
    int yOffset = 0;
    int xOffset = width + 4;
    int missionMapWidth = 20;
    int missionMapHeight = 6;

    for (int y = 5; y <= 5 + missionMapHeight; y++) {
        for (int x = xOffset; x <= 5 + missionMapWidth; x++ ){
            if (y == 5 + yOffset || y == 5 + missionMapHeight) {
                mvprintw(y, x, "-");
            } else if (x == xOffset || x == 5 + missionMapWidth) {
                mvprintw(y, x, "|");
            } else {
                mvprintw(y, x, " ");
            }
        }
    }

    mvprintw(3 + yOffset, xOffset + 8, "Missions");
    mvprintw(4 + yOffset, xOffset + 8, "Stage : %d", stage);
    mvprintw(5 + yOffset, xOffset + 1, " " );
    mvprintw(6 + yOffset, xOffset + 1, " Growth: %d", missionScore.getMGrowth());
    mvprintw(7 + yOffset, xOffset + 1, " Poison: %d", missionScore.getMPoison());
    mvprintw(8 + yOffset, xOffset + 1, " Length: %d", missionScore.getMLength());
}

void GameMap::displayState() const {
    int y0ffset = 9;
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
    mvprintw(11, xOffset+1, " Growth: %d", missionScore.getMissionGrowth());
    mvprintw(12, xOffset+1, " Poison: %d", missionScore.getMissionPoison());
    mvprintw(13, xOffset+1, " Length: %d", missionScore.getMissionLength());
}
