#include "include/MissionScore.h"
#include <ncurses.h>

MissionScore::MissionScore() {
    missionGrowth = 0;
    missionPoison = 0;
    missionLength = 3;
}

void MissionScore::MissionList(int stage){
    switch (stage){
        case 1:
            MLength = 4;
            MGrowth = 1;
            MPoison = 0;
            break;
        case 2:
            MLength = 4;
            MGrowth = 1;
            MPoison = 0;
            break;
        case 3:
            MLength = 4;
            MGrowth = 1;
            MPoison = 0;
            break;
        case 4:
            MLength = 4;
            MGrowth = 1;
            MPoison = 0;
            break;
        default:
            break;
    }
};

int MissionScore::getMissionGrowth() const {
    return missionGrowth;
}

void MissionScore::setMissionGrowth(int value) {
    missionGrowth = value;
}

int MissionScore::getMissionPoison() const {
    return missionPoison;
}

void MissionScore::setMissionPoison(int value) {
    missionPoison = value;
}

int MissionScore::getMissionLength() const {
    return missionLength;
}

void MissionScore::setMissionLength(int value) {
    missionLength = value;
}



int MissionScore::getMGrowth() const {
    return MGrowth;
}

void MissionScore::setMGrowth(int valuem) {
    MGrowth = valuem;
}

int MissionScore::getMPoison() const {
    return MPoison;
}

void MissionScore::setMPoison(int valuem) {
    MPoison = valuem;
}

int MissionScore::getMLength() const {
    return MLength;
}

void MissionScore::setMLength(int valuem) {
    MLength = valuem;
}