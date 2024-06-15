#include "include/GameMap.h"
#include "include/Snake.h"
#include "include/Item.h"
#include "include/MissionScore.h"
#include <ncurses.h>
#include <unistd.h>

int main() {
    // Ncurses 초기화
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);

    // 색상 초기화
    if (has_colors()) {
        start_color();
        init_pair(1, COLOR_GREEN, COLOR_BLACK); // GROWTH 아이템 (초록색)
        init_pair(2, COLOR_RED, COLOR_BLACK);   // POISON 아이템 (빨간색)
        init_pair(3, COLOR_CYAN, COLOR_BLACK); // RANDOM 아이템 (시안색)
    }

    // GameMap 객체 생성 및 초기화
    int stage = 1;
    GameMap map(51, 21, &stage);

    map.TitleMap();

    int press;
    while(true){
        press = getch();
        if(press == 10){
            clear();
            break;
        }
    }

    // Map
    map.initMap();

    // Snake 객체 생성 및 초기화
    Snake snake(map, 10, 10);
    map.printMap();

    // 미션스코어 객체 생성
    MissionScore missionScore;
    missionScore.MissionList(&stage);
    

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
            Item::generateItem(map, items, snake); // snake를 추가로 받음
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

        // 뱀의 속도 변화를 위해 Tick 대신 사용
        if (TimeCount == Tick ) {
            snake.move(InputData);
            map.printMap();
            map.displayState();
            map.displayMissions();
            refresh();
            map.nextStage();
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
        map.displayState();
        map.displayMissions();
        refresh();
        usleep(500000); // 0.5 sec
    }

    // Game Over 메시지 출력
    clear();
    mvprintw(map.getHeight() / 2, map.getWidth() / 2 - 4, "Game Over");
    refresh();
    usleep(5000000); // 5 sec
    clear();


    map.GameOverMap();

    while(true){
        press = getch();
        if(press == 10){
            break;
        }
    }
    
    // Ncurses 종료
    endwin();

    return 0;
}