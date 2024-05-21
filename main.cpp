#include "include/GameMap.h"
#include "include/Snake.h"
#include <ncurses.h>
#include <unistd.h>

int main() {
    // Ncurses 초기화
    initscr();
    noecho();
    curs_set(0);
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);

    // GameMap 객체 생성 및 초기화
    GameMap map(21, 21);
    map.initMap();

    // Snake 객체 생성 및 초기화
    Snake snake(map, 10, 10);
    map.printMap();

    // 틱설정 변수 (ms단위, 1000ms = 1sec)
    const int Tick = 100; // 0.1초에 한번씩 움직임

    // 내부 처리를 위한 변수
    int TimeCount = 0, InputData = -1;

    // 게임 루프
    while (!snake.getGameOver()) {
        // 사용자 입력 처리
        int input = getch();
        if (input != -1) InputData = input;

        // 틱에 따라 작동
        if (TimeCount == Tick) {
            snake.move(InputData);
            map.printMap();
            refresh();
            TimeCount = 0;
        }

        // 틱 제어를 위한 변수
        TimeCount++;

        // 1ms 딜레이
        usleep(1000);
    }


    // Game Over 애니메이션
    for(int i = 0; i < 5; i++){
        clear();
        refresh();
        usleep(500000); // 0.5 sec
        map.printMap();
        refresh();
        usleep(500000); // 0.5 sec
    }

    // Game Over 메시지 출력
    clear();
    mvprintw(map.getHeight() / 2, map.getWidth() / 2 - 4, "Game Over");
    refresh();
    usleep(5000000); // 5 sec

    return 0;
}
