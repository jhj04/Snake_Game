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
    GameMap(int width, int height, int stage);
    ~GameMap();

    void TitleMap() const;
    void GameOverMap() const;
    void WaitingMap() const;

    void initMap();
    void printMap() const;
    void createGate();
    int* getGates() const;
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
    bool Success = false;
    bool gsuccess = false;
    bool psuccess = false;
    bool lsuccess = false;
    bool gatesuccess = false;

    int missionGrowth;
    int missionLength;
    int missionPoison;

};

#endif 
