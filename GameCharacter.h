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

    int maxHP=50;
    Direction direction;
    float movementSpeed=6;
    int counterWalking=0;
    GCharacters gameCharacter;
    string name="name";
    int gil=0;
    bool powerUpLevel=false;
    bool novaAttack=false;

    bool canMoveUp=true;
    bool canMoveDown=true;
    bool canMoveLeft=true;
    bool canMoveRight=true;

    void update();
    void updateMovement(Direction direction1);
    int loadTexture();

    GameCharacter(int posx, int posy, int damage, int hp, GCharacters gameCharacter);
    GameCharacter(){}

    virtual ~GameCharacter(){}

};


#endif //GAME_PROVA3_GAMECHARACTER_H
