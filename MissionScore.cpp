#include "include/MissionScore.h"

// MissionScore 클래스 생성자
MissionScore::MissionScore() 
    : nowGrowth(0), nowPoison(0), nowLength(3), missionLength(0), missionGrowth(0), missionPoison(0), missionGate(0) {
}

// 스테이지별 미션 목록 설정 함수
void MissionScore::MissionList(int* stage) {
    // 스테이지에 따라 미션 목표 설정
    switch (*stage) {
        case 1:
            setMissionLength(3);
            setMissionGrowth(0);
            setMissionPoison(0);
            setMissionGates(1);
            break;
        case 2:
            setMissionLength(3);
            setMissionGrowth(1);
            setMissionPoison(0);
            setMissionGates(0);
            break;
        case 3:
            setMissionLength(3);
            setMissionGrowth(0);
            setMissionPoison(1);
            setMissionGates(0);
            break;
        case 4:
            setMissionLength(4);
            setMissionGrowth(1);
            setMissionPoison(1);
            setMissionGates(1);
            break;
        default:
            break;
    }
    
    // 현재 상태 초기화
    nowGrowth = 0;
    nowPoison = 0;
    nowLength = 3;
    nowGates = 0;
}

// 현재 growth 아이템 개수 반환
int MissionScore::getNowGrowth() const {
    return nowGrowth;
}

// 현재 growth 아이템 개수 설정
void MissionScore::setNowGrowth(int value) {
    nowGrowth = value;
}

// 현재 poison 아이템 개수 반환
int MissionScore::getNowPoison() const {
    return nowPoison;
}

// 현재 poison 아이템 개수
void MissionScore::setNowPoison(int value) {
    nowPoison = value;
}

// 현재 뱀 길이 반환
int MissionScore::getNowLength() const {
    return nowLength;
}

// 현재 뱀 길이 설정
void MissionScore::setNowLength(int value) {
    nowLength = value;
}

// 현재 통과 게이트 개수 반환
int MissionScore::getNowGates() const {
    return nowGates;
}

// 현재 통과 게이트 개수 설정
void MissionScore::setNowGates(int value) {
    nowGates = value;
}

// growth 아이템 미션 개수 반환
int MissionScore::getMissionGrowth() const {
    return missionGrowth;
}

// growth 아이템 미션 개수 설정
void MissionScore::setMissionGrowth(int growth_m) {
    missionGrowth = growth_m;
}

// poison 아이템 미션 개수 반환
int MissionScore::getMissionPoison() const {
    return missionPoison;
}

// poison 아이템 미션 개수 설정
void MissionScore::setMissionPoison(int poison_m) {
    missionPoison = poison_m;
}

// 뱀 길이 미션 반환
int MissionScore::getMissionLength() const {
    return missionLength;
}

// 뱀 길이 미션 설정
void MissionScore::setMissionLength(int length_m) {
    missionLength = length_m;
}

// 통과해야 할 게이트 개수 반환
int MissionScore::getMissionGates() const {
    return missionGate;
}

// 통과해야 할 게이트 개수 설정
void MissionScore::setMissionGates(int gate_m) {
    missionGate = gate_m;
}
