//
// Created by Yasmin on 28/04/2018.
//

#include <iostream>
using namespace std;

#include "GameCharacter.h"


GameCharacter::GameCharacter(int posx, int posy, int damage, int hp, int maxHP, GCharacters gameCharacter):
        Character(posx, posy, damage, hp), maxHP(maxHP), gameCharacter(gameCharacter){
    if(gameCharacter==GCharacters::girl) {
        sprite.setTextureRect(sf::IntRect(0, 0, 24, 32));
    }
    else{
        sprite.setTextureRect(sf::IntRect(0, 32*4, 24, 32));
    }

    rect.setSize(sf::Vector2f(32,32));
    rect.setPosition(posx, posy);
    rect.setFillColor(sf::Color::Blue);
    sprite.setTexture(texture);

}

void GameCharacter ::update() {
    sprite.setPosition(rect.getPosition());
    if(hp>=maxHP){
        hp=maxHP;
    }
}

void GameCharacter::updateMovement(Direction direction1){
        if(direction1==Direction::up){
            if(canMoveUp==true) {
                rect.move(0, -movementSpeed);
                if(gameCharacter==GCharacters::girl)
                    sprite.setTextureRect(sf::IntRect(counterWalking * 24, 0, 24, 32));
                else
                    sprite.setTextureRect(sf::IntRect(counterWalking*24, 32*4, 24, 32));

                direction = Direction::up;

                canMoveUp = true;
                canMoveDown = true;
                canMoveLeft = true;
                canMoveRight = true;
            }
        }

        else if(direction1==Direction::down){
            if(canMoveDown==true){
                rect.move(0, movementSpeed);
                if(gameCharacter==GCharacters::girl)
                    sprite.setTextureRect(sf::IntRect(counterWalking * 24, 32 * 2, 24, 32));
                else
                    sprite.setTextureRect(sf::IntRect(counterWalking*24, 32*6, 24, 32));

                direction = Direction::down;

                canMoveUp = true;
                canMoveDown = true;
                canMoveLeft = true;
                canMoveRight = true;
            }
        }

        else if(direction1==Direction::left){
            if(canMoveLeft==true) {
                rect.move(-movementSpeed, 0);
                if(gameCharacter==GCharacters::girl)
                    sprite.setTextureRect(sf::IntRect(counterWalking * 24, 32 * 3, 24, 32));
                else
                    sprite.setTextureRect(sf::IntRect(counterWalking*24, 32*7, 24, 32));

                direction = Direction::left;

                canMoveUp = true;
                canMoveDown = true;
                canMoveLeft = true;
                canMoveRight = true;
            }
        }

        else if(direction1==Direction::right){
            if(canMoveRight==true) {
                rect.move(movementSpeed, 0);
                if(gameCharacter==GCharacters::girl)
                    sprite.setTextureRect(sf::IntRect(counterWalking * 24, 32, 24, 32));
                else
                    sprite.setTextureRect(sf::IntRect(counterWalking*24, 32*5, 24, 32));

                direction = Direction::right;

                canMoveUp = true;
                canMoveDown = true;
                canMoveLeft = true;
                canMoveRight = true;
            }
        }
        else{} //player not moving

    counterWalking++;
    if(counterWalking==2){
        counterWalking=0;
    }
}

int GameCharacter::loadTexture() {
    if (!texture.loadFromFile("../RisorseSprite/zelda.png")) {
                return EXIT_FAILURE;
    }
}