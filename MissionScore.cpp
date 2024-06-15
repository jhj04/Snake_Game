#include "include/MissionScore.h"
#include <ncurses.h>

MissionScore::MissionScore() 
: nowGrowth(0), nowPoison(0), nowLength(3), missionLength(0), missionGrowth(0), missionPoison(0), missionGate(0) {
}


void MissionScore::MissionList(int* stage){
    switch (*stage){
        case 1:
            setMissionLength(4);
            setMissionGrowth(1);
            setMissionPoison(0);
            setMissionGates(1);
            break;
        case 2:
            setMissionLength(6);
            setMissionGrowth(2);
            setMissionPoison(2);
            setMissionGates(2);
            break;
        case 3:
            setMissionLength(8);
            setMissionGrowth(3);
            setMissionPoison(4);
            setMissionGates(3);
            break;
        case 4:
            setMissionLength(10);
            setMissionGrowth(4);
            setMissionPoison(5);
            setMissionGates(4);
            break;
        default:
            break;
    }
    nowGrowth = 0;
    nowPoison = 0;
    nowLength = 3;
    nowGate = 0;
    
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

void MissionScore::setMissionGrowth(int growth_m) {
    missionGrowth = growth_m;
}

int MissionScore::getMissionPoison() const {
    return missionPoison;
}

void MissionScore::setMissionPoison(int poison_m) {
    missionPoison = poison_m;
}

int MissionScore::getMissionLength() const {
    return missionLength;
}

void MissionScore::setMissionLength(int length_m) {
    missionLength = length_m;
}

int MissionScore::getMissionGates() const {
    return missionGate;
}

void MissionScore::setMissionGates(int gate_m) {
    missionGate = gate_m;
}