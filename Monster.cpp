//
// Created by Yasmin on 27/04/2018.
//

#include "Monster.h"

Monster::Monster(int posx, int posy, int damage, int hp,  Monsters monsterClass):
        Character(posx, posy, damage, hp), monsterClass(monsterClass){
    setStrategy(new TurnAround());
    rect.setSize(sf::Vector2f(32,32));
    rect.setPosition(posx, posy);
    sprite.setTexture(texture);
    switch(monsterClass){
        case Monsters::bat:
        case Monsters ::boss:
            sprite.setTextureRect(sf::IntRect(0,0,32,32));
            break;
        case Monsters ::rat:
            sprite.setTextureRect(sf::IntRect(0,4*32,32,32));
            break;
    }
    loadTexture();
}

Monster::Monster() {}

int Monster::loadTexture() {
    if(monsterClass==Monsters::boss) {
        if (!texture.loadFromFile("../RisorseSprite/boss.png"))
            return EXIT_FAILURE;
    }else{
        if (!texture.loadFromFile("../RisorseSprite/monster2.png"))
            return EXIT_FAILURE;
    }
}


void Monster ::update() {
    sprite.setPosition(rect.getPosition());
    text.setPosition(rect.getPosition().x - rect.getSize().x/2, rect.getPosition().y - rect.getSize().y/2 + 5);
}

void Monster ::updatePosition() {
    update();
    counterWalking++;
    if(counterWalking>=2)
        counterWalking=0;

    canMoveUp = true;
    canMoveDown = true;
    canMoveLeft = true;
    canMoveRight = true;
}

void Monster::updateMovement(GameCharacter* player) {
    //Chooses direction
    behavior->movementBehavior(player, this);

    //move in that direction
    if (getDirection() == Direction::up) {
        if (canMoveUp == true) {
            rect.move(0, -movementSpeed);
            switch(monsterClass){
                case Monsters ::bat:
                case Monsters::boss:
                    sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32 * 3, 32, 32));
                    break;
                case Monsters ::rat:
                    sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32 * 7, 32, 32));
                    break;
            }
            updatePosition();
        }
    }
    else if (getDirection() == Direction::down) {
        if (canMoveDown == true) {
            rect.move(0, movementSpeed);
            switch(monsterClass){
                case Monsters ::bat:
                case Monsters::boss:
                    sprite.setTextureRect(sf::IntRect(counterWalking * 32, 0, 32, 32));
                    break;
                case Monsters ::rat:
                    sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32 * 4, 32, 32));
                    break;
            }
           updatePosition();
        }
    }
    else if (getDirection() == Direction::left) {
        if (canMoveLeft == true) {
            rect.move(-movementSpeed, 0);
            switch(monsterClass){
                case Monsters ::bat:
                case Monsters::boss:
                    sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32, 32, 32));
                    break;
                case Monsters ::rat:
                    sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32 * 5, 32, 32));
                    break;
            }
            updatePosition();
        }
    }
    else if (getDirection() == Direction::right) {
        if (canMoveRight == true) {
            rect.move(movementSpeed, 0);
            switch (monsterClass) {
                case Monsters::bat:
                case Monsters::boss:
                    sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32 * 2, 32, 32));
                    break;
                case Monsters::rat:
                    sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32 * 6, 32, 32));
                    break;
            }
            updatePosition();
        }
    }
    else {//no movement
            counterWalking++;
            if(counterWalking==2)
                counterWalking=0;
        }
}

void Monster::monsterWall() {
    if (getDirection() == Direction::up) {
        canMoveUp = false;
        rect.move(0, movementSpeed);
    } else if (getDirection() == Direction::down) {
        canMoveDown = false;
        rect.move(0, -movementSpeed);
    } else if (getDirection() == Direction::left) {
        canMoveLeft = false;
        rect.move(movementSpeed, 0);
    } else if (getDirection() == Direction::right) {
        canMoveRight = false;
        rect.move(-movementSpeed, 0);
    } else {}
}

void Monster::setAggroed(bool aggroed){
    this->aggroed=aggroed;
    if(this->aggroed)
        setStrategy(new ChaseHero());
    walkingTime.restart();
}

void Monster::setFlee() {
    if(getHP() < 10);
        setStrategy(new Flee());
}


void Monster::setStrategy(Strategy* s){
    behavior= s;
}

void Monster::setMovementSpeed(int movementSpeed){
    this->movementSpeed=movementSpeed;
}

bool Monster::getAggroed(){
    return aggroed;
}
