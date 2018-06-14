//
// Created by Yasmin on 20/05/2018.
//

#ifndef GAME_PROVA3_WALL_H
#define GAME_PROVA3_WALL_H


#include "Entity.h"
#include "Tile.h"
#include "Enumeration.h"


class Wall : public Tile{

public:
    Wall(int x, int y) : posX(x), posY(y) {
        rect.setSize(sf::Vector2f(46, 46));
        rect.setPosition(x, y);
        rect.setFillColor(sf::Color::Black);
        sprite.setPosition(rect.getPosition());
        sprite.setTextureRect(sf::IntRect(0, 0, 46, 46));
    }

    int posX;
    int posY;
};


#endif //GAME_PROVA3_WALL_H
