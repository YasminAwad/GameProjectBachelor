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
    sf::RectangleShape rect;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Text text;

    virtual ~Entity();
};


#endif //GAME_PROVA3_ENTITY_H
