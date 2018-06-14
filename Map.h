//
// Created by Yasmin on 12/06/2018.
//

#ifndef GAME_PROVA3_MAP_H
#define GAME_PROVA3_MAP_H

#include <vector>
#include"Tile.h"
#include "Wall.h"
#include "Enumeration.h"
#include "GameCharacter.h"
#include "Monster.h"


class Map {
public:
    TileEnum textureChoice;

    Map(int width, int height, TileEnum textureChoice);
    ~Map();

    bool wakable=true;

    sf::Texture texture;
    sf::Texture texturewall;
    sf::Texture texturedoor;
    int loadTexture();

    std::vector<Tile*> buffer;
    std::vector<Wall*> wallBuffer;

    void drawWall(sf::RenderWindow *window, GameCharacter *player, std::vector<Monster> monsterArray);
    void drawGrass(sf::RenderWindow *window);
    void drawRoad(sf::RenderWindow *window);
    Tile* getTile(int x, int y);
    int getWidth() const;
    int getHeight() const;

private:
    int width;
    int height;


};


#endif //GAME_PROVA3_MAP_H
