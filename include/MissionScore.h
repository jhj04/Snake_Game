#ifndef MISSIONSCORE_H
#define MISSIONSCORE_H

class MissionScore {
private:
    int nowGrowth;
    int nowPoison;
    int nowLength;
    int nowGates;

    int missionGrowth;
    int missionPoison;
    int missionLength;
    int missionGate;

public:
    MissionScore();

    int getNowGrowth() const; // growth 현재 값 return
    void setNowGrowth(int value); // 현재 growth 미션 값
    int getNowPoison() const; // poison 현재 값 return
    void setNowPoison(int value); // 현재 growth 미션 값
    int getNowLength() const; // length 현재 값 return
    void setNowLength(int value); // 현재 growth 미션 값
    int getNowGates() const; // gate 현재 값 return
    void setNowGates(int value); // 현재 growth 미션 값
    
    void MissionList(int* stage);


    int getMissionGrowth() const;     // growth 미션 값 return
    void setMissionGrowth(int growth_m); // 설정한 growth 미션 값
    int getMissionPoison() const; // poison 미션 값 return
    void setMissionPoison(int poison_m); // 설정한 poison 미션 값
    int getMissionLength() const; // length 미션 값 return
    void setMissionLength(int length_m); // 설정한 length 미션 값
    int getMissionGates() const; // gate 미션 값 return
    void setMissionGates(int gate_m); // 설정한 gate 미션 값


};

#endif
