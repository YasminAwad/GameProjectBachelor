//
// Created by Yasmin on 28/04/2018.
//

#ifndef GAME_PROVA3_GAMECHARACTER_H
#define GAME_PROVA3_GAMECHARACTER_H

#include "Character.h"


enum class GCharacters {boy=0, girl};
//enum class Objects {magic=0, potion, food, key};

class GameCharacter : public Character {
public:

    int maxHP;
    int direction=0; // 1-up, 2-down, 3-left, 4-rigth
    float movementSpeed=3;
    int counterWalking=0;
    GCharacters gameCharacter;
    char name[15];
    sf::Texture textureCharacter;


    void update();
    void updateMovement();
    int loadTexture();
    void setCharacter();

    GameCharacter(int posx, int posy, int damage, int level, int hp, int maxHP, GCharacters gameCharacter);

};


#endif //GAME_PROVA3_GAMECHARACTER_H
