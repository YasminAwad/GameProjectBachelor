//
// Created by Yasmin on 12/06/2018.
//

#include "Map.h"

Map::Map(int width, int height) : width(width), height(height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++)
            buffer.push_back(new Tile(i * 32, j * 32, "x,x"));

    }
}

Map::~Map() {
    buffer.erase(buffer.begin(), buffer.end());
}

int Map::loadTexture() {
    if(!texture.loadFromFile("../RisorseSprite/minecraft1.png")){
        return EXIT_FAILURE;
    }
    for(int i=0; i<buffer.size(); i++) {
        buffer[i]->sprite.setTexture(texture);
    }
}