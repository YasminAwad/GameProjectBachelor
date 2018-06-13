//
// Created by Yasmin on 13/06/2018.
//

#ifndef GAME_PROVA3_MURO_H
#define GAME_PROVA3_MURO_H


#include "Tile.h"

class Muro : public Tile{

public:
    Muro(int x, int y, std::string walltype) : posX(x), posY(y) {
        Tile::setWalkabe(false);
        rect.setSize(sf::Vector2f(46, 46));
        rect.setPosition(x, y);
        rect.setFillColor(sf::Color::Black);
        sprite.setPosition(rect.getPosition());

        sprite.setTextureRect(sf::IntRect(0, 0, 46, 46));

        //[2,1] = Simple Breakable Wall
        if (walltype[0] == '2' && walltype[2] == '1') {
            breakable=true;
        }
    }

    int posX;
    int posY;
    bool breakable= false;
};



#endif //GAME_PROVA3_MURO_H
