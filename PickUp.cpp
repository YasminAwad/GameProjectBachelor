//
// Created by Yasmin on 20/05/2018.
//

#include "PickUp.h"

PickUp::PickUp() {
    rect.setSize(sf::Vector2f(24,24));
    rect.setPosition(500, 500);
    rect.setFillColor(sf::Color::Yellow);
    sprite.setTextureRect(sf::IntRect(0,0,24,24));
    sprite.setTexture(texture);
}

void PickUp::update() {
    sprite.setPosition(rect.getPosition());
}

int PickUp::loadTexture() {
    if (!texture.loadFromFile("../RisorseSprite/object1.png")) {
        return EXIT_FAILURE;
    }
}

//PickUp::~PickUp() {}