//
// Created by Yasmin on 01/07/2018.
//

#ifndef GAME_PROVA3_LOADDISPLAY_H
#define GAME_PROVA3_LOADDISPLAY_H


#include "Entity.h"
class LoadDisplay{
public:

    LoadDisplay(){}
    Entity windowStart;
    Entity title;
    Entity end;
    Entity choiceGirl;
    Entity choiceBoy;

    int setDisplay(sf::Font font);
};


#endif //GAME_PROVA3_LOADDISPLAY_H
