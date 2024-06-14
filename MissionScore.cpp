#include "include/MissionScore.h"
#include <ncurses.h>

MissionScore::MissionScore() {
    nowGrowth = 0;
    nowPoison = 0;
    nowLength = 3;
}

void MissionScore::MissionList(int stage){
    switch (stage){
        case 1:
            missionLength = 4;
            missionGrowth = 1;
            missionPoison = 0;
            break;
        case 2:
            missionLength = 4;
            missionGrowth = 1;
            missionPoison = 0;
            break;
        case 3:
            missionLength = 4;
            missionGrowth = 1;
            missionPoison = 0;
            break;
        case 4:
            missionLength = 4;
            missionGrowth = 1;
            missionPoison = 0;
            break;
        default:
            break;
    }
};

int MissionScore::getNowGrowth() const {
    return nowGrowth;
}

void MissionScore::setNowGrowth(int value) {
    nowGrowth = value;
}

int MissionScore::getNowPoison() const {
    return nowPoison;
}

void MissionScore::setNowPoison(int value) {
    nowPoison = value;
}

int MissionScore::getNowLength() const {
    return nowLength;
}

void MissionScore::setNowLength(int value) {
    nowLength = value;
}



int MissionScore::getMissionGrowth() const {
    return missionGrowth;
}

void MissionScore::setMissionGrowth(int valuem) {
    missionGrowth = valuem;
}

int MissionScore::getMissionPoison() const {
    return missionPoison;
}

void MissionScore::setMissionPoison(int valuem) {
    missionPoison = valuem;
}

int MissionScore::getMissionLength() const {
    return missionLength;
}

void MissionScore::setMissionLength(int valuem) {
    missionLength = valuem;
}