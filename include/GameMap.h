#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "MissionScore.h"

class GameMap {

private:
    int width;
    int height;
    int **mapArray;
    int* gates;
    MissionScore missionScore;

public:
    GameMap(int width, int height, int* stage);
    ~GameMap();

    void TitleMap() const;
    void GameOverMap() const;
    void WaitingMap() const;
    void SuccessMap() const;

    void initMap();
    void printMap() const;
    void createGate();
    int* getGates() const;
    int getNowGates() const; //현재 게이트 불러오기
    int getWidth() const;
    int getHeight() const;
    int getMap(int x, int y) const;
    void setMap(int x, int y, int item);
    void displayState() const; //현재 스코어 상태 출력
    void displayMissions() const; // 현재 스테이지의 미션보드 출력

    void incrementGrowth(); // 아이템 획득에 따른 growth +1
    void incrementPoison(); // 아이템 획득에 따른 poison +1
    void incrementLength(int itemType); // 아이템 획득에 따른 length +-1
    void incrementGates(); // 게이트 통과에 따른 gate +1

    void mGrowth();

    int* stage;

    void nextStage(); // 다음 스테이지로 이동
    void isComplete();
    int growthComplete = 0;
    int poisonComplete = 0;
    int lengthComplete = 0;
    int gateComplete = 0;

    int missionGrowth;
    int missionLength;
    int missionPoison;

};

#endif
