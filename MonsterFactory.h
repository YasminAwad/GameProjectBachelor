//
// Created by Yasmin on 27/06/2018.
//

#ifndef GAME_PROVA3_MONSTERFACTORY_H
#define GAME_PROVA3_MONSTERFACTORY_H

#include "Monster.h"

class MonsterFactory {
public:
    static std::vector<Monster*> createEnemyArray(int size, Monsters monsterType, int HP, int damage);
};


#endif //GAME_PROVA3_MONSTERFACTORY_H
