//
// Created by Yasmin on 13/05/2018.
//

#include "Projectile.h"

Projectile::Projectile() {
    rect.setSize(sf::Vector2f(10,10));
    rect.setPosition(0,0);
    rect.setFillColor(sf::Color::Green);
    sprite.setTexture(textureProjectile);
    sprite.setTextureRect(sf::IntRect(0,0,32,32));
}

int Projectile::loadTexture() {
    if(!textureProjectile.loadFromFile("../RisorseSprite/fireBalls.png")){
        return EXIT_FAILURE;
    }
}

void Projectile::update(){

    if(direction==1){ //up
        rect.move(0,-movementSpeed);
        sprite.setTextureRect(sf::IntRect(counterAnimation*32, 0, 32, 32));
    }

    if(direction==2){
        rect.move(0,movementSpeed); //down
        sprite.setTextureRect(sf::IntRect(counterAnimation*32, 0, 32, 32));
    }

    if(direction==3){
        rect.move(-movementSpeed,0); //left
        sprite.setTextureRect(sf::IntRect(counterAnimation*32, 0, 32, 32));
    }

    if(direction==4){
        rect.move(movementSpeed,0); //right
        sprite.setTextureRect(sf::IntRect(counterAnimation*32, 0, 32, 32));
    }

    counterLifetime++;
    if(counterLifetime>=lifeTime){
        destroy=true;
    }

    counterAnimation++;
    if(counterAnimation>=2){
        counterAnimation=0;
    }

    //sprite set at rect
    sprite.setPosition(rect.getPosition());
}