#ifndef GAME_MAP_H
#define GAME_MAP_H

#include <ncurses.h>

class GameMap {
private:
    int width;  // 맵의 너비
    int height; // 맵의 높이
    int** mapArray; // 맵 배열

public:
    GameMap(int width, int height); // 생성자
    ~GameMap(); // 소멸자
    void initMap(); // 맵 초기화
    void printMap() const;  // 맵 출력
    [[nodiscard]] int getWidth() const;   // 너비 반환
    [[nodiscard]] int getHeight() const;  // 높이 반환
    [[nodiscard]] int getMap(int x, int y) const; // 맵의 특정 좌표 값 반환
    void setMap(int x, int y, int item);    // 맵의 특정 좌표 값 설정
};

#endif
