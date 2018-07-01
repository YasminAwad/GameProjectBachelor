//
// Created by Yasmin on 27/04/2018.
//

#ifndef GAME_PROVA3_MONSTER_H
#define GAME_PROVA3_MONSTER_H

#include "Random.h"
#include "Character.h"
#include "Enumeration.h"
#include "Strategy.h"
#include "GameCharacter.h"

class Strategy;

class Monster: public Character {
public:
    Monsters monsterClass;
    int movementSpeed=1;
    int attackDamage=5;
    int counterWalking=1;
    Direction direction;
    int counter=0;
    int movementLenght=200;
    bool alive=true;
    sf::Clock walkingTime;

    Monster(int posx, int posy, int damage, int hp,  Monsters monsterClass);
    Monster();
    virtual ~Monster(){}

    void update();
    void updatePosition();
    void updateMovement(GameCharacter* player);
    int loadTexture();
    void monsterWall();
    void setStrategy(Strategy* s);
    void setFlee();
    void setAggroed(bool aggroed);
    void setMovementSpeed(int movementSpeed);
    bool getAggroed();

private:
    bool aggroed=false;
    Strategy* behavior;
};


#endif //GAME_PROVA3_MONSTER_H
