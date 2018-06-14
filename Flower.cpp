//
// Created by Yasmin on 14/06/2018.
//

#include "Flower.h"

Flower::Flower(int width, int height): width(width), height(height){

    sprite.setTexture(texture);
}

int Flower::loadTexture() {
    if (!texture.loadFromFile("../RisorseSprite/flower1.png"))
        return EXIT_FAILURE;
    int i=Random::generateRandom(3);
    switch(i){
        case 1:
            sprite.setTextureRect(sf::IntRect(32 * 9, 0, 32, 32));
            break;
        case 2:
            sprite.setTextureRect(sf::IntRect(32 * 5, 32 * 2, 32, 32));
            break;
        case 3:
            sprite.setTextureRect(sf::IntRect(32 * 5, 32 * 2, 32, 32));
            break;
    }
}