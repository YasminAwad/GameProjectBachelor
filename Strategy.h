//
// Created by Yasmin on 26/06/2018.
//

#ifndef GAME_PROVA3_STRATEGY_H
#define GAME_PROVA3_STRATEGY_H

#include "Monster.h"
#include "GameCharacter.h"

class Monster;

class Strategy {
public:
    virtual void movementBehavior(GameCharacter*player, Monster* monster) =0;
    virtual ~Strategy(){}
};

class ChaseHero : public Strategy{
public:
    virtual void movementBehavior(GameCharacter* player, Monster* monster) override;

};

class Flee : public Strategy{
public:
    virtual void movementBehavior(GameCharacter* player, Monster* monster) override;
};

class TurnAround : public Strategy{
public:
    virtual void movementBehavior(GameCharacter* player, Monster* monster) override;
};


#endif //GAME_PROVA3_STRATEGY_H
