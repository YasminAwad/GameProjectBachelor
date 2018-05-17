//
// Created by Yasmin on 28/04/2018.
//

#include <iostream>
using namespace std;

#include "GameCharacter.h"


GameCharacter::GameCharacter(int posx, int posy, int damage, int level, int hp, int maxHP, GCharacters gameCharacter):
        Character(posx, posy, damage, level, hp), maxHP(hp), gameCharacter(gameCharacter) {
    if(gameCharacter==GCharacters::girl) {
        sprite.setTextureRect(sf::IntRect(0, 0, 24, 32));
    }
    else{
        sprite.setTextureRect(sf::IntRect(0, 32*4, 24, 32));
    }
    //cout<<"Inserisci il nome del tuo personaggio:"<<endl;
    //cin>>name;

}

void GameCharacter ::update() {
    sprite.setPosition(rect.getPosition());
}

void GameCharacter::updateMovement(){
    if(gameCharacter==GCharacters::girl){

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            rect.move(0,-movementSpeed);
            sprite.setTextureRect(sf::IntRect(counterWalking*24, 0, 24, 32));
            direction=1;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            rect.move(0,movementSpeed);
            sprite.setTextureRect(sf::IntRect(counterWalking*24, 32*2, 24, 32));
            direction=2;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            rect.move(-movementSpeed,0);
            sprite.setTextureRect(sf::IntRect(counterWalking*24, 32*3, 24, 32));
            direction=3;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            rect.move(movementSpeed,0);
            sprite.setTextureRect(sf::IntRect(counterWalking*24, 32, 24, 32));
            direction=4;
        }

    }
    else{
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            rect.move(0,-movementSpeed);
            sprite.setTextureRect(sf::IntRect(counterWalking*24, 32*4, 24, 32));
            direction=1;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            rect.move(0,movementSpeed);
            sprite.setTextureRect(sf::IntRect(counterWalking*24, 32*6, 24, 32));
            direction=2;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            rect.move(-movementSpeed,0);
            sprite.setTextureRect(sf::IntRect(counterWalking*24, 32*7, 24, 32));
            direction=3;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            rect.move(movementSpeed,0);
            sprite.setTextureRect(sf::IntRect(counterWalking*24, 32*5, 24, 32));
            direction=4;
        }
    }

    counterWalking++;
    if(counterWalking==2){
        counterWalking=0;
    }
}

int GameCharacter::loadTexture() {
    if (!textureCharacter.loadFromFile("../RisorseSprite/zelda.png")) {
                return EXIT_FAILURE;
    }
}



void GameCharacter::setCharacter() {
    rect.setSize(sf::Vector2f(32,32));
    rect.setPosition(posx, posy);
    rect.setFillColor(sf::Color::Blue);
    sprite.setTexture(textureCharacter);

}