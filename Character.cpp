//
// Created by Yasmin on 27/04/2018.
//

#include "Character.h"


Character::Character(int posx, int posy, int damage=10, int hp=50) :
        posx(posx), posy(posy), damage(damage), hp(hp) {}

Character::~Character() {}

int Character::getDamage() const {
    return damage;
}

void Character::setDamage(int damage) {
    this->damage=damage;
}

int Character::getHP() const {
    return hp;
}

void Character::setHP(int hp){
    this->hp=hp;
}

Direction Character::getDirection() const {
    return direction;
}

void Character::setDirection(Direction direction) {
    this->direction=direction;
}