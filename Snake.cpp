#include "include/Snake.h"
#include <ncurses.h>
#include <stdexcept>

Snake::Snake(GameMap& map, int startX, int startY)
        : map(map), headX(startX), headY(startY), lastDirection(KEY_RIGHT), gameOver(false), length(3) {
    // 뱀의 위치를 map에 설정
    map.setMap(startX, startY, 3); // Head
    map.setMap(startX - 1, startY, 4); // Body 1
    map.setMap(startX - 2, startY, 4); // Body 1

    // 뱀의 위치를 Queue에 저장
    body.emplace(startX - 2, startY); // Body 2
    body.emplace(startX - 1, startY); // Body 1
    body.emplace(startX, startY); // Head
}

int Snake::getHeadX() const { // !!
    return headX;
}

int Snake::getHeadY() const { // !!
    return headY;
}

// !! 뱀의 길이 증가
void Snake::grow() { 
    length++;
    body.push(body.back());
}

// !! 뱀의 길이 감소
void Snake::shrink() { 
    if (length > 3) {
        length--;
        int snakeDeleteX = body.front().first;
        int snakeDeleteY = body.front().second;
        body.pop();
        map.setMap(snakeDeleteX, snakeDeleteY, 0);
    }
    else {
        setGameOver();
    }

}

void Snake::move(int direction) {
    int newHeadX = headX;
    int newHeadY = headY;

    // Head 위치 갱신
    updateHeadPosition(newHeadX, newHeadY, direction);

    // 유효한 움직임인지 확인
    if (!isValidMove(newHeadX, newHeadY)) {
        setGameOver();
        return;
    }

    // 뱀의 위치 갱신
    updateSnakePosition(newHeadX, newHeadY);
}

void Snake::updateHeadPosition(int& newHeadX, int& newHeadY, int direction) {
    newHeadX = headX;
    newHeadY = headY;

    if(direction == -1) {
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
    body.emplace(headX, headY);

    // 뱀의 길이가 일정 길이 이상이면 꼬리를 줄임
    while(body.size() >= length) {
        int snakeDeleteX = body.front().first;
        int snakeDeleteY = body.front().second;
        body.pop();
        map.setMap(snakeDeleteX, snakeDeleteY, 0);
    }

    // 헤드 위치 갱신
    headX = newHeadX;
    headY = newHeadY;
}

bool Snake::isValidMove(int x, int y) {
    // !! 빈 공간, 아이템의 경우엔 유효
    return ((map.getMap(x, y) == 0) || (map.getMap(x, y) == 5) || (map.getMap(x, y) == 6));
}

void Snake::setGameOver() {
    gameOver = true;
}

bool Snake::getGameOver() const {
    return gameOver;
}