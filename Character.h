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

    Character (int posx, int posy, int damage, int hp);
    Character(){} //costruttore di default
    virtual ~Character()=0;
};


#endif //GAME_PROVA3_CHARACTER_H
