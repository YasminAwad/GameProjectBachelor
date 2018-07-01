//
// Created by Yasmin on 01/07/2018.
//

#include "LoadDisplay.h"

int LoadDisplay::setDisplay(sf::Font font){

    if (!windowStart.texture.loadFromFile("../RisorseSprite/forest.jpg"))
        return EXIT_FAILURE;
    windowStart.sprite.setPosition(-1270, -600);
    windowStart.sprite.setTexture(windowStart.texture);

    if (!title.texture.loadFromFile("../RisorseSprite/title.png"))
        return EXIT_FAILURE;
    title.sprite.setPosition(-240, -400);
    title.sprite.setTexture(title.texture);

    if (!end.texture.loadFromFile("../RisorseSprite/gameover3.png"))
        return EXIT_FAILURE;
    end.sprite.setPosition(-280, -400);
    end.sprite.setTexture(end.texture);

    if (!choiceBoy.texture.loadFromFile("../RisorseSprite/croppedboy.jpg"))
        return EXIT_FAILURE;
    choiceBoy.sprite.setPosition(-500, -500);
    choiceBoy.sprite.setTexture(choiceBoy.texture);

    if (!choiceGirl.texture.loadFromFile("../RisorseSprite/croppedgirl.jpg"))
        return EXIT_FAILURE;
    choiceGirl.sprite.setPosition(0, -500);
    choiceGirl.sprite.setTexture(choiceGirl.texture);

}