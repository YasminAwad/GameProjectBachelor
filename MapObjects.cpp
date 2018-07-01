//
// Created by Yasmin on 14/06/2018.
//

#include "MapObjects.h"

MapObjects::MapObjects(TileEnum object): object(object){
    rect.setSize(sf::Vector2f(32, 32));
    rect.setPosition(800, 450);
    rect.setFillColor(sf::Color::Green);
    sprite.setPosition(rect.getPosition());
    sprite.setTexture(texture);
}

int MapObjects::loadTexture(){
    switch(object){
        case TileEnum ::door:
            if (!texture.loadFromFile("../RisorseSprite/minecraft1.png"))
                return EXIT_FAILURE;
            sprite.setTextureRect(sf::IntRect(32 * 5, 32 * 5, 32, 32));
            sprite.setPosition(rect.getPosition());
            break;
        case TileEnum ::flower1:
            if (!texture.loadFromFile("../RisorseSprite/flower1.png"))
                return EXIT_FAILURE;
            sprite.setTextureRect(sf::IntRect(32 * 9, 0, 32, 32));
            break;
        case TileEnum ::flower2:
            if (!texture.loadFromFile("../RisorseSprite/flower1.png"))
                return EXIT_FAILURE;
            sprite.setTextureRect(sf::IntRect(32 * 5, 32 * 2, 32, 32));
            break;
    }
}

void MapObjects::update(GameCharacter *player){
    if(open==false){
        if (player->rect.getGlobalBounds().intersects(rect.getGlobalBounds()))
            player->hitWall();
    }
    if(player->rect.getGlobalBounds().intersects(rect.getGlobalBounds()) & open==true){
        isOpen=true;
    }
}