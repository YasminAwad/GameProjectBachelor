//
// Created by Yasmin on 27/04/2018.
//

#ifndef GAME_PROVA3_CHARACTER_H
#define GAME_PROVA3_CHARACTER_H

#include <math.h>
#include <string.h>
#include <SFML/Graphics.hpp>
#include "Entity.h"

class Character: public Entity {
public:
    int damage;
    int hp;
    int posx;
    int posy;

    bool canMoveUp=true;
    bool canMoveDown=true;
    bool canMoveLeft=true;
    bool canMoveRight=true;

    Character (int posx, int posy, int damage, int hp);
    Character(){}
    virtual ~Character()=0;

    int getHP() const;
    int getDamage() const;
    void setDamage(int damage);
};


#endif //GAME_PROVA3_CHARACTER_H
