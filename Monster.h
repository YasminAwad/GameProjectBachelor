//
// Created by Yasmin on 27/04/2018.
//

#ifndef GAME_PROVA3_MONSTER_H
#define GAME_PROVA3_MONSTER_H

#include "Random.h"
#include "Character.h"
#include "Enumeration.h"

class Monster: public Character {
public:
    Monsters monsterClass;
    int movementSpeed=1;
    int attackDamage=5;
    int counterWalking=0;
    Direction direction;
    int counter=0;
    int movementLenght=200;

    bool alive=true;
    bool canMoveUp=true;
    bool canMoveDown=true;
    bool canMoveLeft=true;
    bool canMoveRight=true;

    Monster(int posx, int posy, int damage, int hp,  Monsters monsterClass);
    Monster();
    virtual ~Monster(){}

    void update();
    void updateMovement();
    int loadTexture();
    void monsterWall();
};


#endif //GAME_PROVA3_MONSTER_H
