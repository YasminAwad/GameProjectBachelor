//
// Created by Yasmin on 14/06/2018.
//

#ifndef GAME_PROVA3_MAPOBJECTS_H
#define GAME_PROVA3_MAPOBJECTS_H


#include "Entity.h"
#include "Enumeration.h"
#include "GameCharacter.h"

class MapObjects:public Entity {
public:
    MapObjects(TileEnum object);
    sf::Texture texture;
    TileEnum object;

    bool open=false;

    int loadTexture();
    void update(GameCharacter *player);

    virtual ~MapObjects(){}

};


#endif //GAME_PROVA3_MAPOBJECTS_H
