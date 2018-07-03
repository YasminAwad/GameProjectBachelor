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
    text.setPosition(rect.getPosition().x, rect.getPosition().y - 30);
}

int PickUp::loadTexture() {
    if (!texture.loadFromFile("../RisorseSprite/object1.png")) {
        return EXIT_FAILURE;
    }
}

void PickUp::dropCoin(std::vector<Monster*> monsterArray, int counter) {
    isCoin = true;
    isPowerUp = false;
    isNovaAttack = false;
    isFood = false;
    sprite.setTextureRect(sf::IntRect(13 * 24, 12 * 24, 24, 24));
    rect.setPosition(monsterArray[counter]->rect.getPosition());
}

void PickUp::dropFood(std::vector<Monster*> monsterArray, int counter) {
    isFood = true;
    isNovaAttack = false;
    isPowerUp = false;
    isCoin = false;
    int food = Random::generateRandom0(10);
    sprite.setTextureRect(sf::IntRect(food * 24, 10 * 24, 24, 24));
    rect.setPosition(monsterArray[counter]->rect.getPosition());
}

void PickUp::dropPowerUp(std::vector<Monster*> monsterArray, int counter){
    isPowerUp = true;
    isCoin = false;
    isFood = false;
    isNovaAttack = false;
    sprite.setTextureRect(sf::IntRect(4 * 24, 13 * 24, 24, 24));
    rect.setPosition(monsterArray[counter]->rect.getPosition());
}

void PickUp::dropNovaAttack(std::vector<Monster*> monsterArray, int counter){
    isNovaAttack = true;
    isPowerUp = false;
    isCoin = false;
    isFood = false;
    sprite.setTextureRect(sf::IntRect(24, 13 * 24, 24, 24));
    rect.setPosition(monsterArray[counter]->rect.getPosition());
}