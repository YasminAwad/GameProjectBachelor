//
// Created by Yasmin on 13/05/2018.
//

#ifndef GAME_PROVA3_PROJECTILE_H
#define GAME_PROVA3_PROJECTILE_H

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Enumeration.h"

class Projectile: public Entity {
public:
    int movementSpeed=10;
    int attackDamage=30;
    Direction direction;
    bool destroy=false;
    int counterLifetime=0;
    int lifeTime=50;
    int counterAnimation;

    Projectile();
    virtual ~Projectile(){}

    void update();
    void updateMovement();
    int loadTexture();
};


#endif //GAME_PROVA3_PROJECTILE_H
