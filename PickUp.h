//
// Created by Yasmin on 20/05/2018.
//

#ifndef GAME_PROVA3_PICKUP_H
#define GAME_PROVA3_PICKUP_H

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Monster.h"

class PickUp:public Entity {
public:
    int coinValue=5;
    int foodValue=5;
    int cost=0;
    bool isPowerUp=false;
    bool isNovaAttack=false;
    bool isKey=false;
    bool inShop=false;
    bool isCoin=false;
    bool isFood=false;
    bool destroy=false;

    PickUp();
    virtual ~PickUp(){}
    void update();
    int loadTexture();
    void dropCoin(std::vector<Monster> monsterArray, int counter);
    void dropFood(std::vector<Monster> monsterArray, int counter);
    void dropPowerUp(std::vector<Monster> monsterArray, int counter);
    void dropNovaAttack(std::vector<Monster> monsterArray, int counter);

};


#endif //GAME_PROVA3_PICKUP_H
