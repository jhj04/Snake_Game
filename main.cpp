#include "include/GameMap.h"
#include "include/Snake.h"
#include "include/Item.h"
#include <ncurses.h>
#include <unistd.h>

int main() {
    // Ncurses 초기화
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);

    // GameMap 객체 생성 및 초기화
    GameMap map(21, 21);
    map.initMap();

    // Snake 객체 생성 및 초기화
    Snake snake(map, 10, 10);
    map.printMap();

    // 아이템 벡터 초기화
    std::vector<Item> items;

    // 아이템 유효시간 초기화
    int itemLifetime = 5;

    // 틱설정 변수 (ms단위, 1000ms = 1sec)
    const int Tick = 100; // 0.1초에 한번씩 움직임

    // 내부 처리를 위한 변수
    int TimeCount = 0, InputData = -1;

    // 게임 루프
    while (!snake.getGameOver()) {
        // 아이템 생성
        if (items.size() < 3) {
            Item::generateItem(map, items);
        }
        
        // 사용자 입력 처리
        int input = getch();
        if (input != -1) InputData = input;

        // 아이템 획득 처리
        if (Item::obtainItem(snake, items)) {
            Item::itemEffect(map, snake, items);
        }

        // 만료된 아이템 및 획득된 아이템 제거
        Item::removeItem(map, items, snake, itemLifetime);

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
    for (int i = 0; i < 5; i++) {
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

    endwin(); // Ncurses 종료

    return 0;
}
