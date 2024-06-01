#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "MissionScore.h"

class GameMap {

private:
    int width;
    int height;
    int **mapArray;
    MissionScore missionScore;

public:
    GameMap(int width, int height, int stage);
    ~GameMap();

    void initMap();
    void printMap() const;
    int getWidth() const;
    int getHeight() const;
    int getMap(int x, int y) const;
    void setMap(int x, int y, int item);
    void displayState() const;
    void displayMissions() const;

    void incrementGrowth();
    void incrementPoison();
    void incrementLength(int itemType);

    void mGrowth();

    const MissionScore& getMissionScore() const {
        return missionScore;
    }

    int stage;

    void nextStage(); // 다음 스테이지로 이동
    int currentStage;

    int MGrowth;
    int MLength;
    int MPoison;


};

#endif 
