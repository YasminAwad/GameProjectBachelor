//
// Created by Yasmin on 28/04/2018.
//

#ifndef GAME_PROVA3_GAMECHARACTER_H
#define GAME_PROVA3_GAMECHARACTER_H

#include "Character.h"
#include "Enumeration.h"
#include <string>

using std::string;

class GameCharacter : public Character {
public:

    float tileX=24;
    float tileY=48;
    int maxHP=50;
    Direction direction;
    float movementSpeed=6;
    int counterWalking=0;
    GCharacters gameCharacter;
    int wallet=0;
    bool powerUpLevel=false;
    bool novaAttack=false;
    bool key=false;

    void update();
    void updateMovement(Direction direction1);
    int loadTexture();
    void hitWall();
    int getmaxHP() const;
    void setmaxHP(int maxHP);
    void setHP(int hp);
    void heal(int hp);


    GameCharacter(int posx, int posy, int damage, int hp, int maxHP, GCharacters gameCharacter);
    GameCharacter(){}
    virtual ~GameCharacter(){}

};


#endif //GAME_PROVA3_GAMECHARACTER_H
