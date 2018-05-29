//
// Created by Yasmin on 16/05/2018.
//

#ifndef GAME_PROVA3_TEXTDISPLAY_H
#define GAME_PROVA3_TEXTDISPLAY_H


#include "Entity.h"
#include <string>

using std::string;

class TextDisplay: public Entity {
public:

    string myString="Default";
    float movementSpeed=2;
    int counter=0;
    bool destroy=false;
    int lifetime=100;

    TextDisplay();
    virtual ~TextDisplay(){}
    void update();

};


#endif //GAME_PROVA3_TEXTDISPLAY_H
