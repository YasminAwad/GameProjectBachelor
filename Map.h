//
// Created by Yasmin on 12/06/2018.
//

#ifndef GAME_PROVA3_MAP_H
#define GAME_PROVA3_MAP_H

#include <vector>
#include"Tile.h"
#include "Muro.h"
#include "Enumeration.h"


class Map {
public:
    TileEnum textureChoice;

    Map(int width, int height, TileEnum textureChoice);
    ~Map();

    bool wakable=true;

    sf::Texture texture;
    sf::Texture texturewall;
    int loadTexture();

    std::vector<Tile*> buffer;
    std::vector<Muro*> wallBuffer;
    Tile* door;

    void setTile(int w, int h, const bool walkable);
    Tile* getTile(int x, int y);
    int getWidth() const;
    int getHeight() const;

    bool levelCompleted;

private:
    int width;
    int height;


};


#endif //GAME_PROVA3_MAP_H
