//
// Created by Yasmin on 13/05/2018.
//

#ifndef GAME_PROVA3_PROJECTILE_H
#define GAME_PROVA3_PROJECTILE_H

#include <SFML/Graphics.hpp>
#include "Entity.h"

class Projectile: public Entity {
public:
    int movementSpeed=10;
    int attackDamage=50;
    int direction=0; // 1-up, 2-down, 3-left, 4-rigth
    bool destroy=false;
    int counterLifetime=0;
    int lifeTime=50;
    int counterAnimation;
    sf::Texture textureProjectile;

    Projectile();

    void update();
    void upDateMovement();
    int loadTexture();
};


#endif //GAME_PROVA3_PROJECTILE_H
