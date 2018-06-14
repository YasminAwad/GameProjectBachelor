//
// Created by Yasmin on 12/06/2018.
//

#include "Map.h"

Map::Map(int width, int height, TileEnum textureChoice) : width(width), height(height), textureChoice(textureChoice) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++)
            buffer.push_back(new Tile(i * 32, j * 32));

    }
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++)
            wallBuffer.push_back(new Wall(i * 46, j * 46));

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
void Map::drawGrass(sf::RenderWindow *window){
    for(int i=0; i<buffer.size(); i++)
        window->draw(buffer[i]->sprite);
}

void Map::drawRoad(sf::RenderWindow *window){
    //Horizontal Road
    for(int i=0; i<48; i++)
        window->draw(buffer[23+ i*48]->sprite);
    for(int i=0; i<48; i++)
        window->draw(buffer[24+ i*48]->sprite);
    for(int i=0; i<48; i++)
        window->draw(buffer[25+ i*48]->sprite);

    //Vertical Road
    for(int i=0; i<48; i++)
        window->draw(buffer[24*48+i]->sprite);
    for(int i=0; i<48; i++)
        window->draw(buffer[25*48+i]->sprite);

    //Boss Room
    for(int i=0; i<15; i++) {
        for (int j = 11; j < 38; j++) {
            window->draw(buffer[j * 48 + i]->sprite);
        }
    }

    //Key Room
    for(int i=0; i<10; i++)
        window->draw(buffer[21+ i*48]->sprite);
    for(int i=0; i<10; i++)
        window->draw(buffer[22+ i*48]->sprite);
    for(int i=0; i<10; i++)
        window->draw(buffer[26+ i*48]->sprite);
    for(int i=0; i<10; i++)
        window->draw(buffer[27+ i*48]->sprite);
}
void Map::drawWall(sf::RenderWindow *window, GameCharacter *player, std::vector<Monster> monsterArray) {

    //Vertical
    //Left
    for (int i = 0; i < 33; i++) {
        window->draw(wallBuffer[i]->sprite);
        if (player->rect.getGlobalBounds().intersects(wallBuffer[i]->rect.getGlobalBounds()))
            player->hitWall();
       /*for (int j = 0; j < monsterArray->size(); j++) {
            if (monsterArray[i].rect.getGlobalBounds().intersects(wallBuffer[i]->rect.getGlobalBounds())) {}
            // monsterArray[i].monsterWall;
        }*/
    }
    //Right
    for (int i = 0; i < 33; i++) {
        window->draw(wallBuffer[32 * 48 + i]->sprite);
        if (player->rect.getGlobalBounds().intersects(wallBuffer[32 * 48 + i]->rect.getGlobalBounds()))
            player->hitWall();
        /*for (int j = 0; j < monsterArray.size(); j++) {
            if (monsterArray[i].rect.getGlobalBounds().intersects(wallBuffer[32 * 48 + i]->rect.getGlobalBounds())) {}
            //monsterArray[i].monsterWall;
        }*/
    }

    //Horizontal
    //Up
    for (int i = 0; i < 33; i++) {
        window->draw(wallBuffer[48 * i]->sprite);
        if (player->rect.getGlobalBounds().intersects(wallBuffer[48 * i]->rect.getGlobalBounds()))
            player->hitWall();
    }
    //Down
    for (int i = 0; i < 33; i++) {
        window->draw(wallBuffer[48 * i + 32]->sprite);
        if (player->rect.getGlobalBounds().intersects(wallBuffer[48 * i + 32]->rect.getGlobalBounds()))
            player->hitWall();
    }

    //Key Room
    //Horizontal Up
    for (int i = 0; i < 7; i++) {
        window->draw(wallBuffer[48 * i + 14]->sprite);
        if (player->rect.getGlobalBounds().intersects(wallBuffer[48 * i + 14]->rect.getGlobalBounds()))
            player->hitWall();
    }
    for (int i = 0; i < 7; i++) {
        window->draw(wallBuffer[48 * i + 19]->sprite);
        if (player->rect.getGlobalBounds().intersects(wallBuffer[48 * i + 19]->rect.getGlobalBounds()))
            player->hitWall();
    }

    //Road Horizontal Up
    for (int i = 6; i < 17; i++) {
        if (i != 11) { //pass
            window->draw(wallBuffer[48 * i + 15]->sprite);
            if (player->rect.getGlobalBounds().intersects(wallBuffer[48 * i + 15]->rect.getGlobalBounds()))
                player->hitWall();
        }
    }
    for (int i = 18; i < 33; i++) {
        if (i != 25) {
            window->draw(wallBuffer[48 * i + 15]->sprite);
            if (player->rect.getGlobalBounds().intersects(wallBuffer[48 * i + 15]->rect.getGlobalBounds()))
                player->hitWall();
        }
    }
    //Road Horizontal Down
    for (int i = 6; i < 17; i++) {
        if (i != 11) {
            window->draw(wallBuffer[48 * i + 18]->sprite);
            if (player->rect.getGlobalBounds().intersects(wallBuffer[48 * i + 18]->rect.getGlobalBounds()))
                player->hitWall();
        }
    }
    for (int i = 18; i < 33; i++) {
        if (i != 25) {
            window->draw(wallBuffer[48 * i + 18]->sprite);
            if (player->rect.getGlobalBounds().intersects(wallBuffer[48 * i + 18]->rect.getGlobalBounds()))
                player->hitWall();
        }
    }
    //Road Vertical Left
    for (int i = 18; i < 33; i++) {
        if(i!=24 & i!=25) {
            window->draw(wallBuffer[i + 48 * 16]->sprite);
            if (player->rect.getGlobalBounds().intersects(wallBuffer[i + 48 * 16]->rect.getGlobalBounds()))
                player->hitWall();
        }
    }
    for (int i = 10; i < 16; i++) {
        window->draw(wallBuffer[i + 48 * 16]->sprite);
        if (player->rect.getGlobalBounds().intersects(wallBuffer[i + 48 * 16]->rect.getGlobalBounds()))
            player->hitWall();
    }
    //Road Vertical Right
    for (int i = 18; i < 33; i++) {
        if (i != 24 & i!=25) {
            window->draw(wallBuffer[i + 48 * 18]->sprite);
            if (player->rect.getGlobalBounds().intersects(wallBuffer[i + 48 * 18]->rect.getGlobalBounds()))
                player->hitWall();
        }
    }
    for (int i = 10; i < 16; i++) {
        window->draw(wallBuffer[i + 48 * 18]->sprite);
        if (player->rect.getGlobalBounds().intersects(wallBuffer[i + 48 * 18]->rect.getGlobalBounds()))
            player->hitWall();
    }

    //Boss Room
    for (int i = 0; i < 11; i++) {
        window->draw(wallBuffer[i + 48 * 7]->sprite);
        if (player->rect.getGlobalBounds().intersects(wallBuffer[i + 48 * 7]->rect.getGlobalBounds()))
            player->hitWall();
    }
    for (int i = 0; i < 11; i++) {
        window->draw(wallBuffer[i + 48 * 26]->sprite);
        if (player->rect.getGlobalBounds().intersects(wallBuffer[i + 48 * 26]->rect.getGlobalBounds()))
            player->hitWall();
    }
    for (int i = 7; i < 16; i++) {
            window->draw(wallBuffer[48 * i + 10]->sprite);
            if (player->rect.getGlobalBounds().intersects(wallBuffer[48 * i + 10]->rect.getGlobalBounds()))
                player->hitWall();
    }
    for (int i = 18; i < 27; i++) {
        window->draw(wallBuffer[48 * i + 10]->sprite);
        if (player->rect.getGlobalBounds().intersects(wallBuffer[48 * i + 10]->rect.getGlobalBounds()))
            player->hitWall();
    }
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