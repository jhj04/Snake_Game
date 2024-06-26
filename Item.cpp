#include "include/Item.h"
#include "include/GameMap.h"
#include "include/Snake.h"
#include <cstdlib>

Item::Item(int x, int y, int type) : itemX(x), itemY(y), itemType(type), timestamp(std::time(nullptr)) {} // 아이템 생성자

int Item::getX() const {
    return itemX;
}

int Item::getY() const {
    return itemY;
}

int Item::getType() const {
    return itemType;
}

int Item::getTimestamp() const {
    return timestamp;
}

void Item::generateItem(GameMap& map, std::vector<Item>& items, Snake& snake) {
    int x, y;
    if (items.size() < 3) {
        // 벽을 제외한 공간을 랜덤 지정
        x = rand() % (map.getWidth() - 2) + 1;
        y = rand() % (map.getHeight() - 2) + 1;

        // 해당 위치가 빈 공간이며 뱀의 근처 위치가 아닐 경우, 그 위치에 아이템 추가
        if (snake.isWithinRange(x, y, snake) || map.getMap(x, y) == 0) {
            // GROWTH = 0, POISON = 1, RANDOM = 2
            int type = rand() % 3;
            // 벡터에 새로 만들 아이템 추가
            items.emplace_back(x, y, type);
            // printMap 작동을 위해 GROWTH일 경우 5로, POISON일 경우 6으로 인자를 넘김
            switch (type) {
                case GROWTH: map.setMap(x, y, 5); break;
                case POISON: map.setMap(x, y, 6); break;
                case RANDOM: map.setMap(x, y, 8); break;
            }
        }
    }
}

bool Item::obtainItem(const Snake& snake, const std::vector<Item>& items) {
    int headX = snake.getHeadX();
    int headY = snake.getHeadY();
    for (const auto& item : items) {
        if (item.getX() == headX && item.getY() == headY) {
            return true;
        }
    }
    return false;
}

void Item::itemEffect(GameMap& map, Snake& snake, std::vector<Item>& items) {
    int headX = snake.getHeadX();
    int headY = snake.getHeadY();
    
    // 저장한 모든 아이템과 뱀 머리 위치를 비교
    for (auto it = items.begin(); it != items.end(); ++it) {
        
        // 둘의 위치가 동일할 경우 아이템 효과 적용
        if (it->getX() == headX && it->getY() == headY) {  
            switch (it->getType()) {
                case GROWTH:
                    snake.grow();
                    map.incrementGrowth();
                    map.incrementLength(5);
                    break;
                case POISON:
                    snake.shrink();
                    map.incrementPoison();
                    map.incrementLength(6);
                    break;
                case RANDOM: // 랜덤으로 길이가 증가하거나 감소
                    if (rand() % 2 == 0) {
                        snake.grow();
                        map.incrementGrowth();
                    } else {
                        snake.shrink();
                        map.incrementPoison();
                    }
                    break;
            }
            // 아이템을 맵에서 제거
            map.setMap(it->getX(), it->getY(), 0);
            // 아이템 삭제
            items.erase(it); 
            break;
        }
    }
}

void Item::removeItem(GameMap& map, std::vector<Item>& items, const Snake& snake, int lifetime) {
    std::time_t currentTime = std::time(nullptr);
    auto it = items.begin();
    while (it != items.end()) {
        // 유효시간이 만료 됐을 경우 아이템 제거
        bool expired = std::difftime(currentTime, it->getTimestamp()) > lifetime;
        if (expired) {
            map.setMap(it->getX(), it->getY(), 0);
            it = items.erase(it);
        } else {
            ++it;
        }
    }
}
