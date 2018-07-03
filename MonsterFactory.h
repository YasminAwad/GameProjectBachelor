//
// Created by Yasmin on 03/07/2018.
//

#ifndef GAME_PROVA3_MONSTERFACTORY_H
#define GAME_PROVA3_MONSTERFACTORY_H

#include "Monster.h"

class MonsterFactory {
public:
    static std::vector<Monster*> MonsterArrayGenerator(int size, int hp, int damage);

};


#endif //GAME_PROVA3_MONSTERFACTORY_H
