//
// Created by Yasmin on 13/05/2018.
//

#ifndef GAME_PROVA3_ENTITY_H
#define GAME_PROVA3_ENTITY_H


#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics.hpp>

class Entity {
public:
    //Physical Object
    sf::RectangleShape rect;
    sf::Sprite sprite;
    sf::Text text;

    bool active=false;
    bool deleteit=false;
    int x=0;
    int y=0;
};


#endif //GAME_PROVA3_ENTITY_H
