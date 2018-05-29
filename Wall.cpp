//
// Created by Yasmin on 20/05/2018.
//

#include "Wall.h"

Wall::Wall() {
    rect.setSize(sf::Vector2f(50,50));
    rect.setPosition(400, 400);
    rect.setFillColor(sf::Color::Blue);
    //sprite.setTextureRect(sf::IntRect(0,0,32,32));
    //sprite.setTexture(texture);

    rect.setSize(sf::Vector2f(46,46));
    rect.setFillColor(sf::Color::Blue);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, 46, 46));
}

void Wall::update(){
    sprite.setPosition(rect.getPosition());
}

int Wall::loadTexture() {
    if (!texture.loadFromFile("../RisorseSprite/alberi1.png")) {
        return EXIT_FAILURE;
    }
}

//Wall::~Wall() {}