//
// Created by Yasmin on 20/05/2018.
//

#include "Wall.h"

Wall::Wall(WallTexture textureChoice): textureChoice(textureChoice) {
    switch(textureChoice){
        case WallTexture ::tree:
            rect.setSize(sf::Vector2f(46,46));
            sprite.setTexture(texture);
            sprite.setTextureRect(sf::IntRect(0, 0, 46, 46));
            break;
        case WallTexture ::flower:
            rect.setSize(sf::Vector2f(32,32));
            sprite.setTexture(texture);
            sprite.setTextureRect(sf::IntRect(9*32, 1*32, 32, 32));
            break;
    }

    rect.setPosition(400, 400);
    rect.setFillColor(sf::Color::Blue);
}

void Wall::update(){
    sprite.setPosition(rect.getPosition());
}

int Wall::loadTexture() {
    switch(textureChoice){
        case WallTexture::tree:
            if (!texture.loadFromFile("../RisorseSprite/alberi1.png"))
                return EXIT_FAILURE;
            break;
        case WallTexture ::flower:
            if (!texture.loadFromFile("../RisorseSprite/flower1.png"))
                return EXIT_FAILURE;
            break;
    }
}

//Wall::~Wall() {}