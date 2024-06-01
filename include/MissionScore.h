#ifndef MISSIONSCORE_H
#define MISSIONSCORE_H

class MissionScore {
private:
    int missionGrowth;
    int missionPoison;
    int missionLength;

    int MGrowth;
    int MPoison;
    int MLength;

public:
    MissionScore();

    // 아이템 획득에 따라 증감하는 상태
    int getMissionGrowth() const;
    void setMissionGrowth(int value);
    int getMissionPoison() const;
    void setMissionPoison(int value);
    int getMissionLength() const;
    void setMissionLength(int value);
    void MissionList(int stage);

    // 설정한 미션 값
    int getMGrowth() const;
    void setMGrowth(int valuem);
    int getMPoison() const;
    void setMPoison(int valuem);
    int getMLength() const;
    void setMLength(int valuem);

};

#endif
