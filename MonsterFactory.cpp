//
// Created by Yasmin on 03/07/2018.
//

#include "MonsterFactory.h"

std::vector<Monster*> MonsterFactory::MonsterArrayGenerator(int size, int hp, int damage){
    std::vector<Monster*> monsterArray;

    //MonsterFactory
    for(int i=1; i<size; i++){
        monsterArray.push_back(new Monster(100,1300, damage, hp, Monsters::bat));
        monsterArray.push_back(new Monster(1300, 1300, damage, hp, Monsters::rat));
    }

    monsterArray[0]->rect.setPosition(100, 100);
    monsterArray[1]->rect.setPosition(200,400);
    monsterArray[2]->rect.setPosition(1300,200);
    monsterArray[3]->rect.setPosition(1400,500);
    monsterArray[4]->rect.setPosition(300,1100);
    monsterArray[5]->rect.setPosition(500,1200);
    monsterArray[6]->rect.setPosition(1200,1000);
    monsterArray[7]->rect.setPosition(1000,1100);
    monsterArray[8]->rect.setPosition(100, 1300);
    monsterArray[9]->rect.setPosition(1300, 1300);

    return monsterArray;
}