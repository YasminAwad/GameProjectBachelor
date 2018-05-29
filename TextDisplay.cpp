//
// Created by Yasmin on 16/05/2018.
//

#include "TextDisplay.h"

TextDisplay::TextDisplay() {
    text.setColor(sf::Color::Red); //???
    text.setCharacterSize(30);
    //text.setPosition(0,0);
    text.setString(myString);
}

void TextDisplay::update() {
    text.move(0,-movementSpeed);

    counter++;

    if(counter>=lifetime){
        destroy=true;
    }
}

//TextDisplay::~TextDisplay() {}