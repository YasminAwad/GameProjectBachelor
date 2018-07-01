//
// Created by Yasmin on 12/06/2018.
//

#ifndef GAME_PROVA3_TILE_H
#define GAME_PROVA3_TILE_H

#include "Entity.h"


class Tile : public Entity {
public:

    Tile(){}
    Tile(int x,int y) {
        rect.setSize(sf::Vector2f(32, 32));
        rect.setPosition(x, y);
        rect.setFillColor(sf::Color::Green);
        sprite.setPosition(rect.getPosition());
        sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
    }
};


#endif //GAME_PROVA3_TILE_H
