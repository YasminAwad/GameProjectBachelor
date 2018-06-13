//
// Created by Yasmin on 12/06/2018.
//

#include "Map.h"

Map::Map(int width, int height, TileEnum textureChoice) : width(width), height(height), textureChoice(textureChoice) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++)
            buffer.push_back(new Tile(i * 32, j * 32, "x,x"));

    }
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++)
            wallBuffer.push_back(new Muro(i * 46, j * 46, "x,x"));

    }
}

Map::~Map() {
    buffer.erase(buffer.begin(), buffer.end());
    wallBuffer.erase(wallBuffer.begin(), wallBuffer.end());
}

int Map::loadTexture() {
    if (!texture.loadFromFile("../RisorseSprite/minecraft1.png")) {
        return EXIT_FAILURE;
    }

    if (!texturewall.loadFromFile("../RisorseSprite/alberi1.png")) {
        return EXIT_FAILURE;
    }
    for (int i = 0; i < buffer.size(); i++) {
        buffer[i]->sprite.setTexture(texture);
        wallBuffer[i]->sprite.setTexture(texturewall);
        switch (textureChoice) {
            case TileEnum::grass:
                buffer[i]->sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
                break;
            case TileEnum::road:
                buffer[i]->sprite.setTextureRect(sf::IntRect(32 * 2, 0, 32, 32));
                break;
            case TileEnum::bossRoom:
                buffer[i]->sprite.setTextureRect(sf::IntRect(32 * 1, 0, 32, 32));
                break;
        }
    }
}

void Map::setTile(int x, int y, const bool walkable) {
    buffer[x + y * width]->setWalkabe(walkable);
}

Tile* Map::getTile(int x, int y) {
    return buffer[x + y * width];
}

int Map::getWidth() const {
    return width;
}

int Map::getHeight() const {
    return height;
}