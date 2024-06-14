#ifndef MISSIONSCORE_H
#define MISSIONSCORE_H

class MissionScore {
private:
    int nowGrowth;
    int nowPoison;
    int nowLength;

    int missionGrowth;
    int missionPoison;
    int missionLength;
    int missionGate;

public:
    MissionScore();

    // 아이템 획득에 따라 증감하는 상태
    int getNowGrowth() const;
    void setNowGrowth(int value);
    int getNowPoison() const;
    void setNowPoison(int value);
    int getNowLength() const;
    void setNowLength(int value);
    
    void MissionList(int stage);

    // 설정한 미션 값
    int getMissionGrowth() const;
    void setMissionGrowth(int valuem);
    int getMissionPoison() const;
    void setMissionPoison(int valuem);
    int getMissionLength() const;
    void setMissionLength(int valuem);
    int getMissionGates() const;
    void setMissionGates(int valuem);

};

#endif
