#ifndef ITEM_H
#define ITEM_H

#include "GameMap.h"
#include "Snake.h"
#include <vector> // 맵에 존재하는 아이템을 저장하기 위해 벡터 include
#include <ctime>

#define GROWTH 0
#define POISON 1
#define RANDOM 2

class Item {
private:
    int itemX, itemY, itemType; // 아이템 x좌표, y좌표, 타입(GROWTH/POISON)
    std::time_t timestamp; // 아이템이 생성된 시간
public:
    Item(int x, int y, int type);

    static void generateItem(GameMap& map, std::vector<Item>& items, Snake& snake); // 아이템을 맵에 생성하는 함수
    static bool obtainItem(const Snake& snake, const std::vector<Item>& items); // 아이템 획득 여부 확인 함수
    static void itemEffect(GameMap& map, Snake& snake, std::vector<Item>& items); // 아이템의 효과를 구현하는 함수
    static void removeItem(GameMap& map,std::vector<Item>& items, const Snake& snake, int lifetime); // 유효시간이 지나거나, 획득한 아이템을 지우는 함수
    
    // 아이템 위치, 타입, 생성시간 getter
    int getX() const;
    int getY() const;
    int getType() const;
    int getTimestamp() const;
};
#endif