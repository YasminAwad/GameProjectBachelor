//
// Created by Yasmin on 20/05/2018.
//

#ifndef GAME_PROVA3_WALL_H
#define GAME_PROVA3_WALL_H


#include "Entity.h"
#include "Tile.h"
#include "Enumeration.h"


class Wall: public Entity {
    public:
        WallTexture textureChoice;

        Wall(WallTexture textureChoice);
        virtual ~Wall(){}

        int loadTexture();
        void update();


};


#endif //GAME_PROVA3_WALL_H
