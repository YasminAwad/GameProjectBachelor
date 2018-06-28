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

    if (!texturewall.loadFromFile("../RisorseSprite/alberi1.png")) {
        return EXIT_FAILURE;
    }

    if(textureChoice==TileEnum::flower1 || textureChoice==TileEnum::flower2) {
        if (!texture.loadFromFile("../RisorseSprite/flower1.png")) {
            return EXIT_FAILURE;
        }
        for (int i = 0; i < buffer.size(); i++) {
            buffer[i]->sprite.setTexture(texture);
            if(textureChoice==TileEnum::flower1)
                buffer[i]->sprite.setTextureRect(sf::IntRect(0, 32 * 3, 32, 32));
            if(textureChoice==TileEnum::flower2)
                buffer[i]->sprite.setTextureRect(sf::IntRect(32 * 7, 32 * 2, 32, 32));
        }
    }
    else {
        if (!texture.loadFromFile("../RisorseSprite/minecraft1.png")) {
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
}
void Map::drawGrass(sf::RenderWindow *window){
    for(int i=0; i<buffer.size(); i++)
        window->draw(buffer[i]->sprite);
}

void Map::drawFlower1(sf::RenderWindow *window){ //FIXME
    for(int i=0; i<48; i++)
        window->draw(buffer[i*42 + 73]->sprite);
}

void Map::drawFlower2(sf::RenderWindow *window) {

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
        window->draw(buffer[23*48+i]->sprite);
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

void Map::monsterWallCollision(int a, std::vector<Monster> *monsterArray, std::vector<Monster>::iterator counter2) {
   /* int toll = 5;

    for (counter2 = monsterArray->begin(); counter2 != monsterArray->end(); counter2++) {

        if (abs(static_cast<int>(wallBuffer[a]->rect.getPosition().y + 32 - counter2->rect.getPosition().y)) < toll &&
            abs(static_cast<int>(wallBuffer[a]->rect.getPosition().x - counter2->rect.getPosition().x)) < 32 - toll) {
            counter2->canMoveUp = false;
        }
        if (abs(static_cast<int>(wallBuffer[a]->rect.getPosition().y - 32 - counter2->rect.getPosition().y )) < toll &&
            abs(static_cast<int>(wallBuffer[a]->rect.getPosition().x - counter2->rect.getPosition().x)) < 32 - toll) {
            counter2->canMoveDown = false;
        }

        if (abs(static_cast<int>(wallBuffer[a]->rect.getPosition().y - counter2->rect.getPosition().y )) < 32 - toll &&
            abs(static_cast<int>(wallBuffer[a]->rect.getPosition().x + 32 - counter2->rect.getPosition().x)) < toll) {
            counter2->canMoveLeft = false;
        }
        if (abs(static_cast<int>(wallBuffer[a]->rect.getPosition().y - counter2->rect.getPosition().y )) < 32 - toll &&
            abs(static_cast<int>(wallBuffer[a]->rect.getPosition().x - 32 - counter2->rect.getPosition().x)) < toll) {
            counter2->canMoveRight = false;
        }
        counter2++;
    }*/
}

void Map::bossWallCollision(int a, Monster* boss){
    int toll=5;

    if (abs(static_cast<int>(wallBuffer[a]->rect.getPosition().y + 32 - boss->rect.getPosition().y)) < toll &&
            abs(static_cast<int>(wallBuffer[a]->rect.getPosition().x - boss->rect.getPosition().x)) < 32 - toll) {
        boss->canMoveUp = false;
    }
    if (abs(static_cast<int>(wallBuffer[a]->rect.getPosition().y - 32 - boss->rect.getPosition().y )) < toll &&
            abs(static_cast<int>(wallBuffer[a]->rect.getPosition().x - boss->rect.getPosition().x)) < 32 - toll) {
        boss->canMoveDown = false;
    }

    if (abs(static_cast<int>(wallBuffer[a]->rect.getPosition().y - boss->rect.getPosition().y )) < 32 - toll &&
            abs(static_cast<int>(wallBuffer[a]->rect.getPosition().x + 32 - boss->rect.getPosition().x)) < toll) {
        boss->canMoveLeft = false;
    }
    if (abs(static_cast<int>(wallBuffer[a]->rect.getPosition().y - boss->rect.getPosition().y )) < 32 - toll &&
            abs(static_cast<int>(wallBuffer[a]->rect.getPosition().x - 32 - boss->rect.getPosition().x)) < toll) {
        boss->canMoveRight = false;
    }
}

void Map::drawWall(sf::RenderWindow *window, GameCharacter *player, std::vector<Monster> *monsterArray, Monster *boss) {
    std::vector<Monster>::iterator counter2;

    //Vertical
    //Left
    for (int i = 0; i < 33; i++) {
        window->draw(wallBuffer[i]->sprite);
        if (player->rect.getGlobalBounds().intersects(wallBuffer[i]->rect.getGlobalBounds()))
            player->hitWall();
        wallBuffer[i]->isWalkable=false;
        monsterWallCollision(i, monsterArray, counter2);
    }
    //Right
    for (int i = 0; i < 33; i++) {
        window->draw(wallBuffer[32 * 48 + i]->sprite);
        if (player->rect.getGlobalBounds().intersects(wallBuffer[32 * 48 + i]->rect.getGlobalBounds()))
            player->hitWall();
        wallBuffer[32 * 48 + i]->isWalkable=false;
        monsterWallCollision(32 * 48 + i, monsterArray, counter2);
    }

    //Horizontal
    //Up
    for (int i = 0; i < 33; i++) {
        window->draw(wallBuffer[48 * i]->sprite);
        if (player->rect.getGlobalBounds().intersects(wallBuffer[48 * i]->rect.getGlobalBounds()))
            player->hitWall();
        wallBuffer[48 * i]->isWalkable=false;
        monsterWallCollision(48*i, monsterArray, counter2);
        bossWallCollision(48*i, boss);

    }
    //Down
    for (int i = 0; i < 33; i++) {
        window->draw(wallBuffer[48 * i + 32]->sprite);
        if (player->rect.getGlobalBounds().intersects(wallBuffer[48 * i + 32]->rect.getGlobalBounds()))
            player->hitWall();
        wallBuffer[48 * i + 32]->isWalkable=false;
        monsterWallCollision(32 * 48 + i, monsterArray, counter2);
    }

    //Key Room
    //Horizontal Up
    for (int i = 0; i < 7; i++) {
        window->draw(wallBuffer[48 * i + 14]->sprite);
        if (player->rect.getGlobalBounds().intersects(wallBuffer[48 * i + 14]->rect.getGlobalBounds()))
            player->hitWall();
        wallBuffer[48 * i + 14]->isWalkable=false;
        monsterWallCollision(48*i+14, monsterArray, counter2);
    }
    for (int i = 0; i < 7; i++) {
        window->draw(wallBuffer[48 * i + 19]->sprite);
        if (player->rect.getGlobalBounds().intersects(wallBuffer[48 * i + 19]->rect.getGlobalBounds()))
            player->hitWall();
        wallBuffer[48 * i + 19]->isWalkable=false;
        monsterWallCollision(48*i+19, monsterArray, counter2);
    }

    //Road Horizontal Up
    for (int i = 6; i < 16; i++) {
        if (i != 11 & i!=12) { //pass
            window->draw(wallBuffer[48 * i + 15]->sprite);
            if (player->rect.getGlobalBounds().intersects(wallBuffer[48 * i + 15]->rect.getGlobalBounds()))
                player->hitWall();
            wallBuffer[48 * i + 15]->isWalkable=false;
            monsterWallCollision(48*i+15, monsterArray, counter2);
        }
    }
    for (int i = 18; i < 33; i++) {
        if (i != 23 & i!=22) {
            window->draw(wallBuffer[48 * i + 15]->sprite);
            if (player->rect.getGlobalBounds().intersects(wallBuffer[48 * i + 15]->rect.getGlobalBounds()))
                player->hitWall();
            wallBuffer[48 * i + 15]->isWalkable=false;
            monsterWallCollision(48*i+15, monsterArray, counter2);
        }
    }
    //Road Horizontal Down
    for (int i = 6; i < 16; i++) {
        if (i != 11 & i!=12) {
            window->draw(wallBuffer[48 * i + 18]->sprite);
            if (player->rect.getGlobalBounds().intersects(wallBuffer[48 * i + 18]->rect.getGlobalBounds()))
                player->hitWall();
            wallBuffer[48 * i + 18]->isWalkable=false;
            monsterWallCollision(48*i+18, monsterArray, counter2);
        }
    }
    for (int i = 18; i < 33; i++) {
        if (i != 23 & i!=22) {
            window->draw(wallBuffer[48 * i + 18]->sprite);
            if (player->rect.getGlobalBounds().intersects(wallBuffer[48 * i + 18]->rect.getGlobalBounds()))
                player->hitWall();
            monsterWallCollision(48*i+18, monsterArray, counter2);
        }
    }
    //Road Vertical Left
    for (int i = 18; i < 33; i++) {
        if(i!=24 & i!=25) {
            window->draw(wallBuffer[i + 48 * 15]->sprite);
            if (player->rect.getGlobalBounds().intersects(wallBuffer[i + 48 * 15]->rect.getGlobalBounds()))
                player->hitWall();
            wallBuffer[i + 48 * 15]->isWalkable=false;
            monsterWallCollision(i+48*15, monsterArray, counter2);
        }
    }
    for (int i = 10; i < 16; i++) {
        window->draw(wallBuffer[i + 48 * 15]->sprite);
        if (player->rect.getGlobalBounds().intersects(wallBuffer[i + 48 * 15]->rect.getGlobalBounds()))
            player->hitWall();
        wallBuffer[i + 48 * 15]->isWalkable=false;
        monsterWallCollision(i+48*15, monsterArray, counter2);
    }
    //Road Vertical Right
    for (int i = 18; i < 33; i++) {
        if (i != 24 & i!=25) {
            window->draw(wallBuffer[i + 48 * 18]->sprite);
            if (player->rect.getGlobalBounds().intersects(wallBuffer[i + 48 * 18]->rect.getGlobalBounds()))
                player->hitWall();
            wallBuffer[i + 48 * 18]->isWalkable=false;
            monsterWallCollision(i+48*18, monsterArray, counter2);
        }
    }
    for (int i = 10; i < 16; i++) {
        window->draw(wallBuffer[i + 48 * 18]->sprite);
        if (player->rect.getGlobalBounds().intersects(wallBuffer[i + 48 * 18]->rect.getGlobalBounds()))
            player->hitWall();
        wallBuffer[i + 48 * 18]->isWalkable=false;
        monsterWallCollision(i+48*18, monsterArray, counter2);
    }

    //Boss Room
    for (int i = 0; i < 11; i++) {
        window->draw(wallBuffer[i + 48 * 7]->sprite);
        if (player->rect.getGlobalBounds().intersects(wallBuffer[i + 48 * 7]->rect.getGlobalBounds()))
            player->hitWall();
        wallBuffer[i + 48 * 7]->isWalkable=false;
        monsterWallCollision(i+48*7, monsterArray, counter2);
        bossWallCollision(i+48*7, boss);
    }
    for (int i = 0; i < 11; i++) {
        window->draw(wallBuffer[i + 48 * 26]->sprite);
        if (player->rect.getGlobalBounds().intersects(wallBuffer[i + 48 * 26]->rect.getGlobalBounds()))
            player->hitWall();
        wallBuffer[i + 48 * 26]->isWalkable=false;
        monsterWallCollision(i+48*26, monsterArray, counter2);
        bossWallCollision(i+48*26, boss);
    }
    for (int i = 7; i < 16; i++) {
        window->draw(wallBuffer[48 * i + 10]->sprite);
        if (player->rect.getGlobalBounds().intersects(wallBuffer[48 * i + 10]->rect.getGlobalBounds()))
            player->hitWall();
        wallBuffer[48 * i + 10]->isWalkable=false;
        monsterWallCollision(48*i+10, monsterArray, counter2);
        bossWallCollision(i*48+10, boss);
    }
    for (int i = 18; i < 27; i++) {
        window->draw(wallBuffer[48 * i + 10]->sprite);
        if (player->rect.getGlobalBounds().intersects(wallBuffer[48 * i + 10]->rect.getGlobalBounds()))
            player->hitWall();
        wallBuffer[48 * i + 10]->isWalkable=false;
        monsterWallCollision(48*i+10, monsterArray, counter2);
        bossWallCollision(i*48+10, boss);
    }
}


int Map::getWidth() const {
    return width;
}

int Map::getHeight() const {
    return height;
}