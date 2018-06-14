//
// Created by Yasmin on 14/06/2018.
//

#ifndef GAME_PROVA3_FLOWER_H
#define GAME_PROVA3_FLOWER_H


#include "Entity.h"
#include "Random.h"
#include "Tile.h"

class Flower: public Entity {
public:
    Flower(int width, int height);
    int loadTexture();
    std::vector<Tile*> buffer;

private:
    int width;
    int height;
};


#endif //GAME_PROVA3_FLOWER_H
