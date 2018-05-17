//
// Created by Yasmin on 27/04/2018.
//

#ifndef GAME_PROVA3_MONSTER_H
#define GAME_PROVA3_MONSTER_H

#include "Random.h"
#include "Character.h"

enum class Monsters {snake, spider, idra};

class Monster: public Character {
public:
    Monsters monsterClass;
    int movementSpeed=1;
    int attackDamage=5;
    int counterWalking=0;
    int direction=0; // 1-u, 2-down ...
    sf::Texture textureMonster;
    int counter=0;
    int movementLenght=200;
    bool alive=true;

    Monster(int posx, int posy, int damage, int level, int hp, Monsters monsterClass);
    Monster();

    //distruttore??

    void monsterAttack (Monster *enemy);
    void update();
    void updateMovement();
    int loadTexture();
    void generateMonster();


};


#endif //GAME_PROVA3_MONSTER_H
