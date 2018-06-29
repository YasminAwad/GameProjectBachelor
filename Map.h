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
    sf::Texture texture;
    sf::Texture texturewall;
    std::vector<Tile*> buffer;
    std::vector<Wall*> wallBuffer;
    std::vector<Wall*>::iterator iter;

    Map(int width, int height, TileEnum textureChoice);
    ~Map();
    int loadTexture();
    void drawWall(sf::RenderWindow *window, GameCharacter *player);
    void drawGrass(sf::RenderWindow *window);
    void drawFlower1(sf::RenderWindow *window);
    void drawFlower2(sf::RenderWindow *window);
    void drawRoad(sf::RenderWindow *window);
    int getWidth() const;
    int getHeight() const;

private:
    int width;
    int height;


};


#endif //GAME_PROVA3_MAP_H
