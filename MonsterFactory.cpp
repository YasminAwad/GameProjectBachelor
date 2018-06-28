//
// Created by Yasmin on 27/06/2018.
//

#include "MonsterFactory.h"

std::vector<Monster*> MonsterFactory::createEnemyArray(int size, Monsters monsterType, int HP, int damage) {
    std::vector<Monster*> array;
    for(int i=0;i<size;i++)
        array.push_back(new Monster(0,0,damage,HP,monsterType));
    return array;
}