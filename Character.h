//
// Created by Yasmin on 27/04/2018.
//

#ifndef GAME_PROVA3_CHARACTER_H
#define GAME_PROVA3_CHARACTER_H

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Enumeration.h"

class Character: public Entity {
public:

    bool canMoveUp=true;
    bool canMoveDown=true;
    bool canMoveLeft=true;
    bool canMoveRight=true;

    Character (int posx, int posy, int damage, int hp);
    Character(){}
    virtual ~Character()=0;

    int getDamage() const;
    void setDamage(int damage);
    int getHP() const;
    void setHP(int hp);
    Direction getDirection() const;
    void setDirection(Direction direction);

private:
    int posx;
    int posy;
    int hp;
    int damage;
    Direction direction;

};


#endif //GAME_PROVA3_CHARACTER_H
