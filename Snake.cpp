#include "include/Snake.h"
#include <ncurses.h>
#include <iostream>


Snake::Snake(GameMap& map, int startX, int startY)
    : map(map), headX(startX), headY(startY), lastDirection(KEY_RIGHT), gameOver(false), length(3) {
    // 뱀의 위치를 map에 설정
    map.setMap(startX, startY, 3); // Head
    map.setMap(startX - 1, startY, 4); // Body 1
    map.setMap(startX - 2, startY, 4); // Body 2

    // 뱀의 위치를 Queue에 저장
    body.emplace(startX - 2, startY); // Body 2
    body.emplace(startX - 1, startY); // Body 1
    body.emplace(startX, startY); // Head
}

void Snake::move(int direction) {
    int newHeadX = headX;
    int newHeadY = headY;

    // Head 위치 갱신
    updateHeadPosition(newHeadX, newHeadY, direction);

    // Handle gate
    if (isGate(newHeadX, newHeadY)) {
        int* outGateCoor = outGate(newHeadX, newHeadY);
        direction = outGateCoor[0];
        newHeadX = outGateCoor[1];
        newHeadY = outGateCoor[2];

        // Head 위치 갱신
        updateHeadPosition(newHeadX, newHeadY, direction);

        // 문제가 되는 부분: (lastDirection 업데이트 안 됨)
        lastDirection = direction;
    }

    // 유효한 움직임인지 확인
    else if (!isValidMove(newHeadX, newHeadY)) {
        setGameOver();
        return;
    }

    // 뱀의 위치 갱신
    updateSnakePosition(newHeadX, newHeadY);
    
    if (direction != -1) {
        lastDirection = direction;
    }

}

void Snake::updateHeadPosition(int& newHeadX, int& newHeadY, int direction) {
    if (direction == -1) {
        direction = lastDirection;
    }

    switch (direction) {
        case KEY_UP:
            newHeadY--;
            break;
        case KEY_DOWN:
            newHeadY++;
            break;
        case KEY_LEFT:
            newHeadX--;
            break;
        case KEY_RIGHT:
            newHeadX++;
            break;
        default:
            break;
    }

    lastDirection = direction;
}

void Snake::updateSnakePosition(int newHeadX, int newHeadY) {
    // 뱀의 위치 갱신 (Map)
    map.setMap(headX, headY, 4); 
    map.setMap(newHeadX, newHeadY, 3); 

    // 뱀의 위치 갱신 (Queue)
    body.emplace(newHeadX, newHeadY);

    // 뱀의 길이가 일정 길이 이상이면 꼬리를 줄임
    while (body.size() > length) {
        int snakeDeleteX = body.front().first;
        int snakeDeleteY = body.front().second;
        body.pop();

        if (!isGate(snakeDeleteX, snakeDeleteY)) {
            map.setMap(snakeDeleteX, snakeDeleteY, 0);
        }
    }

    // 헤드 위치 갱신
    headX = newHeadX;
    headY = newHeadY;
}

int* Snake::outGate(int ex, int ey) {
    static int out[3];
    int* gates = map.getGates();
    int gate1X = gates[0];
    int gate1Y = gates[1];
    int gate2X = gates[2];
    int gate2Y = gates[3];

    if (ex == gate1X && ey == gate1Y) {
        out[1] = gate2X;
        out[2] = gate2Y;
    } 
    else if (ex == gate2X && ey == gate2Y) {
        out[1] = gate1X;
        out[2] = gate1Y;
    }
    else {
        // should never reach this point
        out[1] = ex; 
        out[2] = ey;
    }
    
    if (out[1] == 0) out[0] = KEY_RIGHT;
    else if (out[2] == 0) out[0] = KEY_DOWN;
    else if (out[1] == map.getWidth() - 1) out[0] = KEY_LEFT;
    else if (out[2] == map.getHeight() - 1) out[0] = KEY_UP;
    else out[0] = lastDirection; // Maintain last direction, might be a problem
    return out;
}

bool Snake::isValidMove(int x, int y) {
    int mapValue = map.getMap(x, y);
    return mapValue == 0 || mapValue == 7;
}

bool Snake::isGate(int x, int y) {
    return map.getMap(x, y) == 7;
}

void Snake::setGameOver() {
    gameOver = true;
}

bool Snake::getGameOver() const {
    return gameOver;
}

std::queue<std::pair<int, int>> body;
