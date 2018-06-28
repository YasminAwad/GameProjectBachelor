//
// Created by Yasmin on 27/04/2018.
//

#include "Character.h"


Character::Character(int posx, int posy, int damage=10, int hp=50) :
        posx(posx), posy(posy), damage(damage), hp(hp) {//inline
}

Character::~Character() {}

int Character::getHP() const {
    return hp;
}

/*void Character::setHP(int hp) {
    this->hp=hp;
    if(this->hp<0)
        this->hp=0;
    if(this->hp>maxHP)
        this->hp=maxHP;
}*/