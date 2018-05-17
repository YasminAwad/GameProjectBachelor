//
// Created by Yasmin on 27/04/2018.
//

#include "Monster.h"

Monster::Monster(int posx, int posy, int damage, int level, int hp, Monsters monsterClass)
        :Character(posx, posy, damage, level, hp),
         monsterClass(monsterClass){

    sprite.setTextureRect(sf::IntRect(0,0,32,32));

}

Monster::Monster() {
    rect.setSize(sf::Vector2f(32,32));
    rect.setPosition(posx, posy);

    sprite.setTexture(textureMonster);
    sprite.setTextureRect(sf::IntRect(0,0,32,32));
}

int Monster::loadTexture() {
    if(!textureMonster.loadFromFile("../RisorseSprite/monster2.png")){
        return EXIT_FAILURE;
    }
}


void Monster ::update() {
    sprite.setPosition(rect.getPosition());
}

void Monster::updateMovement() {

    //direction = Random::generateRandom(4);

    if (direction == 1) { //up
        rect.move(0, -movementSpeed);
        sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32*3, 32, 32));
    } else {
        if (direction == 2) { //down
            rect.move(0, movementSpeed);
            sprite.setTextureRect(sf::IntRect(counterWalking * 32, 0, 32, 32));
        } else {
            if (direction == 3) { //left
                rect.move(-movementSpeed, 0);
                sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32, 32, 32));
            } else {
                if (direction == 4) { //right
                    rect.move(movementSpeed, 0);
                    sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32*2, 32, 32));
                } else {
                    //no movement
                }
            }
        }
    }


    counterWalking++;
    if(counterWalking==2){
        counterWalking=0;
    }

    counter++;
    if(counter>=movementLenght){
        counter=0;
        direction=Random::generateRandom(10);
    }


}



/*
void Monster::monsterAttack(Monster *enemy) {
    switch (monsterClass){
        case Monsters::snake : //snape: attacco ravvicinato
            if(posx==enemy->posx){
                enemy->attack(enemy);
            }
            break;

        case Monsters::spider : //spider: attacco ravvicinato
            if((abs(enemy->posx - posx) < 30) && (abs(enemy->posy - posy) < 30)) { // se è ad una certa distanza (cerchio)
                //attacco a distanza:
                //sprite per sparare
                enemy->attack(enemy);
            }
            break;

        case Monsters::idra : //idra: attacco ravvicinato e a distanza
            if((abs(enemy->posx - posx) < 30) && (abs(enemy->posy - posy) < 30)) { // se è ad una certa distanza (cerchio)
                //attacco a distanza:
                //sprite per sparare
                enemy->attack(enemy);
            }
            else if (posx==enemy->posx){
                enemy->attack(enemy);
            }
            break;
    }
}*/