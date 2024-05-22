#ifndef SNAKE_H
#define SNAKE_H

#include "GameMap.h"
#include <queue>
#include <utility>

class Snake {
private:
    int headX, headY;   // 뱀의 머리 위치
    int lastDirection;  // 마지막 이동 방향
    GameMap& map;       // 게임 맵에 대한 참조
    int length;         // 뱀의 길이
    bool gameOver; // 게임 오버 여부
    std::queue<std::pair<int, int>> body;  // 뱀 몸통의 위치를 저장하는 큐

    void updateSnakePosition(int newHeadX, int newHeadY);  // 뱀의 위치를 갱신하는 함수
    bool isValidMove(int x, int y);  // 이동이 유효한지 확인하는 함수
    void setGameOver();   // 게임 오버 처리

public:
    Snake(GameMap& map, int startX, int startY); // 생성자
    void move(int direction);   // 방향키 입력에 따라 뱀을 움직이는 함수
    [[nodiscard]] bool getGameOver() const;   // 게임 오버 여부 반환
    void updateHeadPosition(int& newHeadX, int& newHeadY, int direction); // Head 위치를 갱신하는 함수
};

#endif
