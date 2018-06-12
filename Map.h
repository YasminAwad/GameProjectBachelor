//
// Created by Yasmin on 12/06/2018.
//

#ifndef GAME_PROVA3_MAP_H
#define GAME_PROVA3_MAP_H

#include <vector>
#include"Tile.h"


class Map {
public:
    Map(int width, int height);
    ~Map();

    sf::Texture texture;
    int loadTexture();

    std::vector<Tile*> buffer;

private:
    int width;
    int height;


};


#endif //GAME_PROVA3_MAP_H
