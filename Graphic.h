//
// Created by Yasmin on 05/05/2018.
//

#ifndef GAME_PROVA3_GRAPHIC_H
#define GAME_PROVA3_GRAPHIC_H


#include <SFML/Graphics.hpp>

#include "GameCharacter.h"

class Graphic {
public:
  //  sf::Sprite spriteCharacter;
   // sf::Texture textureCharacter;
    sf::RectangleShape rect;

    int loadTexture();
    void setCharacter(GameCharacter character);

};


#endif //GAME_PROVA3_GRAPHIC_H
