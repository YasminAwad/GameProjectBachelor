//
// Created by Yasmin on 27/04/2018.
//

#include "Monster.h"

Monster::Monster(int posx, int posy, int damage, int hp,  Monsters monsterClass):
        Character(posx, posy, damage, hp), monsterClass(monsterClass){
    hp=3;
    rect.setSize(sf::Vector2f(32,32));
    rect.setPosition(posx, posy);
    //Random::generateRandom(1000)
    switch(monsterClass){
        case Monsters::bat:
            sprite.setTexture(texture);
            sprite.setTextureRect(sf::IntRect(0,0,32,32));
            break;
        case Monsters ::rat:
            sprite.setTexture(texture);
            sprite.setTextureRect(sf::IntRect(0,4*32,32,32));
            break;
        case Monsters ::boss:
            break;
    }
}

Monster::Monster() {
    hp=3;
    rect.setSize(sf::Vector2f(32,32));
    rect.setPosition(Random::generateRandom(1000), Random::generateRandom(1000));

    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0,0,32,32));
}

int Monster::loadTexture() {
    if(!texture.loadFromFile("../RisorseSprite/monster2.png")){
        return EXIT_FAILURE;
    }
}


void Monster ::update() {
    sprite.setPosition(rect.getPosition());
    text.setPosition(rect.getPosition().x - rect.getSize().x/2, rect.getPosition().y - rect.getSize().y/2 + 5);
}

void Monster::updateMovement() {

    //direction = Random::generateRandom(4);

    if (direction == Direction::up) {
        if (canMoveUp == true) {
            rect.move(0, -movementSpeed);
            switch(monsterClass){
                case Monsters ::bat:
                    sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32 * 3, 32, 32));
                    break;
                case Monsters ::rat:
                    sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32 * 7, 32, 32));
                    break;
            }

            canMoveUp = true;
            canMoveDown = true;
            canMoveLeft = true;
            canMoveRight = true;
        }
    }
    else if (direction == Direction::down) {
        if (canMoveDown == true) {
            rect.move(0, movementSpeed);
            switch(monsterClass){
                case Monsters ::bat:
                    sprite.setTextureRect(sf::IntRect(counterWalking * 32, 0, 32, 32));
                    break;
                case Monsters ::rat:
                    sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32 * 4, 32, 32));
                    break;
            }

            canMoveUp = true;
            canMoveDown = true;
            canMoveLeft = true;
            canMoveRight = true;
        }
    }
    else if (direction == Direction::left) {
        if (canMoveLeft == true) {
            rect.move(-movementSpeed, 0);
            switch(monsterClass){
                case Monsters ::bat:
                    sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32, 32, 32));
                    break;
                case Monsters ::rat:
                    sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32 * 5, 32, 32));
                    break;
            }

            canMoveUp = true;
            canMoveDown = true;
            canMoveLeft = true;
            canMoveRight = true;
        }
    }
    else if (direction == Direction::right) {
        if (canMoveRight == true) {
            rect.move(movementSpeed, 0);
            switch(monsterClass){
                case Monsters ::bat:
                    sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32 * 2, 32, 32));
                    break;
                case Monsters ::rat:
                    sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32 * 6, 32, 32));
                    break;
            }

            canMoveUp = true;
            canMoveDown = true;
            canMoveLeft = true;
            canMoveRight = true;
        }
    }
    else {} //no movement

    counterWalking++;
    if(counterWalking==2){
        counterWalking=0;
    }

    counter++;
    if(counter>=movementLenght) {
        counter = 0;
        int myRandom = Random::generateRandom(10);
        switch(myRandom){
            case 1:
                direction = Direction::up;
                break;
            case 2:
                direction = Direction::down;
                break;
            case 3:
                direction = Direction::left;
                break;
            case 4:
                direction = Direction::right;
                break;
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
                direction = Direction::null;
                break;

        }
    }
}

void Monster::monsterWall() {
    if (direction == Direction::up) {
        canMoveUp = false;
        rect.move(0, movementSpeed);
    }
    else if (direction == Direction::down) {
        canMoveDown = false;
        rect.move(0, -movementSpeed);
    }
    else if (direction == Direction::left) {
        canMoveLeft = false;
        rect.move(movementSpeed, 0);
    }
    else if (direction == Direction::right) {
        canMoveRight = false;
        rect.move(-movementSpeed, 0);
    } else {}
}