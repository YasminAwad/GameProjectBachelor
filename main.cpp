#include <iostream>
#include <SFML/Graphics.hpp>

#include "GameCharacter.h"
#include "Projectile.h"
#include "Monster.h"
#include "Random.h"
#include "TextDisplay.h"
#include "PickUp.h"
#include "Wall.h"
#include "Sound.h"
#include "TileMap.h"
#include "CustomWall.h"

using namespace std;

int main() {

    //Variables
    srand(time(NULL));
    int counter;
    int counter2;
    sf::Clock clock;
    sf::Clock clock2;
    sf::Clock clock3;
    int food;
    int myRandom;
    int monsterRandom;
    int enumMonsterRandom;

    //create the main window
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "GAME_PROVA3");
    window.setFramerateLimit(60);

    //View
    sf::View view1(sf::FloatRect(200,200,300,200));
    view1.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
    view1.setCenter(sf::Vector2f(view1.getSize().x/2, view1.getSize().y/2));
    window.setView(view1);

    GameCharacter player(window.getPosition().x/2 + 530, window.getPosition().y/2 + 1480, 10, 50, GCharacters::boy);

    //set the icon
    sf::Image icon;
    if (!icon.loadFromFile("../RisorseSprite/videogamepad.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    //Music
   /* Sound sound;
    sound.loadSound();
    sound.music.play();
    sound.music.setLoop(true);*/

    //Create a graphical text to display
    sf::Font font;
    if(!font.loadFromFile("../RisorseFont/pokemon.ttf")){
        return EXIT_FAILURE;
    }

    sf::Text text("Gil", font, 25);
    //text.setColor(sf::Color::White);
    text.setPosition(0,0);

    sf::Text textHP("HP", font, 25);
    textHP.setColor(sf::Color::Black);

    //Load a sprite to display
    sf::Texture textureForest;

    if (!textureForest.loadFromFile("../RisorseSprite/forest.jpg")) {
        return EXIT_FAILURE;
    }

    sf::Sprite forest;
    sf::RectangleShape rect;
    forest.setTexture(textureForest);
    rect.setPosition(0, 0);
    forest.setPosition(rect.getPosition());

    player.loadTexture();

    //Projectile Vector Array
    vector<Projectile>::const_iterator iter;
    vector <Projectile> projectileArray;

    //Projectile Object
    Projectile projectile1;
    projectile1.loadTexture();

    //Monster Vector Array
    vector<Monster>::const_iterator iter4;
    vector<Monster> monsterArray;

    //Monster Object BAT
    Monster monster1(Random::generateRandom(window.getSize().x), Random::generateRandom(window.getSize().y), 5, 30, Monsters::bat);
    monster1.rect.setPosition(400,200);
    monsterArray.push_back(monster1);
    monster1.loadTexture();

    //Monster Object RAT
    Monster monster2(Random::generateRandom(window.getSize().x), Random::generateRandom(window.getSize().y), 5, 30, Monsters::rat);
    monster2.rect.setPosition(400,200);
    monsterArray.push_back(monster2);
    monster2.loadTexture();

    //Text Vector Array
    vector<TextDisplay>::const_iterator iter8;
    vector<TextDisplay> textdisplayArray;

    //Text Object
    TextDisplay textdisplay1;
    textdisplay1.text.setFont(font);

    //Coin Vector Array
    vector<PickUp>::const_iterator iter11;
    vector<PickUp> pickupArray;

    //Coin Object
    PickUp pickup1;
    pickupArray.push_back(pickup1);
    pickup1.loadTexture();

    //Wall Vector Array
    vector<Wall>::const_iterator iter15;
    vector<Wall> wallArray;

    //Wall Object
    Wall wall1;
    wallArray.push_back(wall1);
    wall1.loadTexture();

    //Custom Room

    //Boss Wall sx
    CustomWall wallbossSX(16,0,45);
    counter=0;
    while(counter<wallbossSX.wallSize){
        wall1.rect.setPosition(wallbossSX.rectSizeX * counter + wallbossSX.roomStartX, wallbossSX.rectSizeY + wallbossSX.roomStartY);
        wallArray.push_back(wall1);
        counter++;
    }

    //Boss Wall dx
    CustomWall wallbossDX(16,800,45);
    counter=0;
    while(counter<wallbossSX.wallSize){
        wall1.rect.setPosition(wallbossSX.rectSizeX * counter + wallbossDX.roomStartX, wallbossSX.rectSizeY + wallbossDX.roomStartY);
        wallArray.push_back(wall1);
        counter++;
    }
    //Create Vertical Wall
    counter=0;
    while(counter<wallbossSX.wallSize){
        wall1.rect.setPosition(wallbossSX.rectSizeX*wallbossSX.wallSize + wallbossSX.roomStartY, wallbossSX.rectSizeY*counter + wallbossSX.roomStartX);
        wallArray.push_back(wall1);
        counter++;
    }

// define the level with an array of tile indices
    const int level[] =
            {
                    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,//1
                    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,//2
                    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,//3
                    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,//4
                    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,//5
                    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,//6
                    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,//7
                    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,//8
                    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,//9
                    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,//10
                    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,//11
                    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,//12
                    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,//13
                    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,//14
                    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,//15
                    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,//16
                    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,//17
                    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//18
                    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//19
                    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//20
                    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//21
                    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//22
                    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//23
                    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//24
                    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//25
                    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//26
                    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//27
                    2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//28
                    2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//30
                    2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//31
                    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,//32
                    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,//33
                    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,//34
                    2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//35
                    2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//36
                    2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//37
                    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//38
                    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//39
                    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//40
                    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//41
                    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//42
                    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//43
                    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//44
                    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//45
                    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//46
                    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//47
                    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//48
                    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//49


            };

    // create the tilemap from the level definition
    TileMap map;
    if (!map.load("../RisorseSprite/minecraft1.png", sf::Vector2u(32, 32), level, 16*3, 8*3*2))
        return -1;

//start the game loop

// run the program as long as the window is open
    while (window.isOpen()) {
        //process events
        sf::Event event;
        while (window.pollEvent(event)) {
// "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();

//escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }

//clear screen
        window.clear();

        sf::Time elapsed1=clock.getElapsedTime();
        sf::Time elapsed2=clock2.getElapsedTime();
        sf::Time elapsed3=clock3.getElapsedTime();

        window.draw(map);

        player.update();

        //Player Movement
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            player.updateMovement(Direction::up);
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            player.updateMovement(Direction::down);
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            player.updateMovement(Direction::left);
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            player.updateMovement(Direction::right);

        //Fire Missle (Space Bar)
        if(elapsed1.asSeconds()>=0.5){
            clock.restart();
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {

                //sound.soundShot.play();

                //PowerUp Attack
                if(player.powerUpLevel==true) {
                    projectile1.rect.setPosition(player.rect.getPosition().x, player.rect.getPosition().y);
                    projectile1.direction = player.direction;
                    projectileArray.push_back(projectile1);

                    projectile1.rect.setPosition(player.rect.getPosition().x + Random::generateRandom(50), player.rect.getPosition().y + Random::generateRandom(50));
                    projectile1.direction = player.direction;
                    projectileArray.push_back(projectile1);

                    projectile1.rect.setPosition(player.rect.getPosition().x + Random::generateRandom(50), player.rect.getPosition().y + Random::generateRandom(50));
                    projectile1.direction = player.direction;
                    projectileArray.push_back(projectile1);
                }
                else if(player.novaAttack==true){
                    projectile1.rect.setPosition(player.rect.getPosition().x + player.rect.getSize().x/2 - projectile1.rect.getSize().x/2, player.rect.getPosition().y + player.rect.getSize().y/2 - projectile1.rect.getSize().y/2);
                    projectile1.direction=Direction ::up;
                    projectileArray.push_back(projectile1);

                    projectile1.rect.setPosition(player.rect.getPosition().x + player.rect.getSize().x/2 - projectile1.rect.getSize().x/2, player.rect.getPosition().y + player.rect.getSize().y/2 - projectile1.rect.getSize().y/2);
                    projectile1.direction=Direction ::down;
                    projectileArray.push_back(projectile1);

                    projectile1.rect.setPosition(player.rect.getPosition().x + player.rect.getSize().x/2 - projectile1.rect.getSize().x/2, player.rect.getPosition().y + player.rect.getSize().y/2 - projectile1.rect.getSize().y/2);
                    projectile1.direction=Direction ::left;
                    projectileArray.push_back(projectile1);

                    projectile1.rect.setPosition(player.rect.getPosition().x + player.rect.getSize().x/2 - projectile1.rect.getSize().x/2, player.rect.getPosition().y + player.rect.getSize().y/2 - projectile1.rect.getSize().y/2);
                    projectile1.direction=Direction ::right;
                    projectileArray.push_back(projectile1);
                }
                else{
                    //Normal Attack
                    projectile1.rect.setPosition(player.rect.getPosition().x, player.rect.getPosition().y);
                    projectile1.direction = player.direction;
                    projectileArray.push_back(projectile1);
                }
            }
        }


        //Projectiles Collides with Monster
        counter=0;
        for(iter=projectileArray.begin(); iter!=projectileArray.end(); iter++){
            counter2=0;
            for(iter4=monsterArray.begin(); iter4!=monsterArray.end(); iter4++){
                if(projectileArray[counter].rect.getGlobalBounds().intersects(monsterArray[counter2].rect.getGlobalBounds())){
                    projectileArray[counter].destroy=true;
                    //delete &projectileArray[counter];

                    //sound.soundCollision.play();

                    //Text Display
                    textdisplay1.text.setString(to_string(projectileArray[counter].attackDamage));
                    textdisplay1.text.setPosition(monsterArray[counter2].rect.getPosition().x + monsterArray[counter2].rect.getSize().x/2, monsterArray[counter2].rect.getPosition().y - monsterArray[counter2].rect.getSize().y/2);
                    textdisplayArray.push_back(textdisplay1);

                    monsterArray[counter2].hp-=projectileArray[counter].attackDamage;

                    if(monsterArray[counter2].hp<=0){
                        monsterArray[counter2].alive=false;
                        //delete &monsterArray[counter2];
                    }
                }
                counter2++;
            }
            counter++;
        }

        //Monster Collides with Player (player takes damage)
        if(elapsed2.asSeconds()>=0.5){
            clock2.restart();
            counter=0;
            for(iter4=monsterArray.begin(); iter4!=monsterArray.end(); iter4++){
                if(player.rect.getGlobalBounds().intersects(monsterArray[counter].rect.getGlobalBounds())){

//                    sound.soundPDamage.play();

                    //Text Display
                    textdisplay1.text.setString(to_string(monsterArray[counter].attackDamage));
                    textdisplay1.text.setPosition(player.rect.getPosition().x + player.rect.getSize().x/2, player.rect.getPosition().y - player.rect.getSize().y/2);
                    textdisplayArray.push_back(textdisplay1);

                    player.hp -= monsterArray[counter].attackDamage;
                    player.powerUpLevel=false;
                    player.novaAttack=false;
                }
                counter++;
            }
        }

        //Monster Collides with Wall
        counter=0;
        counter2=0;
        for(iter4=monsterArray.begin(); iter4!=monsterArray.end(); iter4++){
            for(iter15=wallArray.begin(); iter15!=wallArray.end(); iter15++){
                if (monsterArray[counter].rect.getGlobalBounds().intersects(
                        wallArray[counter2].rect.getGlobalBounds())) {

                    //Hit Wall
                    if (monsterArray[counter].direction == Direction::up) {
                        monsterArray[counter].canMoveUp = false;
                        monsterArray[counter].rect.move(0, monster1.movementSpeed);
                    }
                    else if (monsterArray[counter].direction == Direction::down) {
                        monsterArray[counter].canMoveDown = false;
                        monsterArray[counter].rect.move(0, -monster1.movementSpeed);
                    }
                    else if (monsterArray[counter].direction == Direction::left) {
                        monsterArray[counter].canMoveLeft = false;
                        monsterArray[counter].rect.move(monster1.movementSpeed, 0);
                    }
                    else if (monsterArray[counter].direction == Direction::right) {
                        monsterArray[counter].canMoveRight = false;
                        monsterArray[counter].rect.move(-monster1.movementSpeed, 0);
                    } else {}
                }
                counter2++;
            }
            counter++;
        };

        //Player Collides with PickUp Item
        counter=0;
        for(iter11=pickupArray.begin(); iter11!=pickupArray.end(); iter11++) {
            if (player.rect.getGlobalBounds().intersects(pickupArray[counter].rect.getGlobalBounds())) {
                if (pickupArray[counter].isCoin == true) {
                    //sound.soundCoin.setVolume(100);
                    //sound.soundCoin.play();
                    player.gil += pickupArray[counter].coinValue;
                }
                if(pickupArray[counter].isPowerUp==true){
                    //sound.soundPower.play();
                    player.powerUpLevel=true;
                    player.novaAttack=false;
                }
                if(pickupArray[counter].isNovaAttack==true){
                    //sound.soundPower.play();
                    player.powerUpLevel=false;
                    player.novaAttack=true;
                }
                if(pickupArray[counter].isFood==true){
                    //sound.soundCoin.setVolume(100);
                    //sound.soundCoin.play();
                    player.hp += pickupArray[counter].foodValue;
                    if(player.hp>=player.maxHP) //FIXME
                        player.hp==player.maxHP;
                    }

                pickupArray[counter].destroy = true;
            }
            counter++;
        }

        //Player Collides with Wall
        counter=0;
        for(iter15=wallArray.begin(); iter15!=wallArray.end(); iter15++){
            if(player.rect.getGlobalBounds().intersects(wallArray[counter].rect.getGlobalBounds())) {
                //Hit Wall
                if (player.direction == Direction::up) {
                    player.canMoveUp = false;
                    player.rect.move(0, player.movementSpeed);
                }
                else if (player.direction == Direction::down) {
                    player.canMoveDown = false;
                    player.rect.move(0, -player.movementSpeed);
                }
                else if (player.direction == Direction::left) {
                    player.canMoveLeft = false;
                    player.rect.move(player.movementSpeed, 0);
                }
                else if (player.direction == Direction::right) {
                    player.canMoveRight = false;
                    player.rect.move(-player.movementSpeed, 0);
                }
                else{}
            }
            counter++;
        }

        //Delete Dead Monsters
        counter=0;
        for(iter4=monsterArray.begin(); iter4!=monsterArray.end(); iter4++){
            myRandom=Random::generateRandom(4);
            if(monsterArray[counter].alive==false){

                //Drop Coin
                if(myRandom==1){ //voglio più monete e meno attacchi speciali
                    pickup1.isCoin=true;
                    pickup1.isPowerUp=false;
                    pickup1.isNovaAttack=false;
                    pickup1.isFood=false;
                    pickup1.sprite.setTextureRect(sf::IntRect(13*24,12*24,24,24));
                    pickup1.rect.setPosition(monsterArray[counter].rect.getPosition());
                    pickupArray.push_back((pickup1));
                }

                //Drop Food
                if(myRandom==2){
                    pickup1.isFood=true;
                    pickup1.isNovaAttack=false;
                    pickup1.isPowerUp=false;
                    pickup1.isCoin=false;
                    food=Random::generateRandom0(10);
                    pickup1.sprite.setTextureRect(sf::IntRect(food*24,10*24,24,24));
                    pickup1.rect.setPosition(monsterArray[counter].rect.getPosition());
                    pickupArray.push_back(pickup1);
                }

                //Drop PowerUp
                if(myRandom==3){
                    pickup1.isPowerUp=true;
                    pickup1.isCoin=false;
                    pickup1.isFood=false;
                    pickup1.isNovaAttack=false;
                    pickup1.sprite.setTextureRect(sf::IntRect(4*24,13*24,24,24));
                    pickup1.rect.setPosition(monsterArray[counter].rect.getPosition());
                    pickupArray.push_back(pickup1);
                    player.powerUpLevel=true;
                }

                //Drop NovaAttack
                if(myRandom==4){
                    pickup1.isNovaAttack=true;
                    pickup1.isPowerUp=false;
                    pickup1.isCoin=false;
                    pickup1.isFood=false;
                    pickup1.sprite.setTextureRect(sf::IntRect(24,13*24,24,24));
                    pickup1.rect.setPosition(monsterArray[counter].rect.getPosition());
                    pickupArray.push_back(pickup1);
                    player.novaAttack=true;
                }

                monsterArray.erase(iter4);
                break;
            }
            counter++;
        }

        //Delete Projectiles
        counter=0;
        for(iter=projectileArray.begin(); iter!=projectileArray.end(); iter++){
            if(projectileArray[counter].destroy == true){
                projectileArray.erase(iter);
                break;
            }
            counter++;
        }

        //Delete Text Display
        counter=0;
        for(iter8=textdisplayArray.begin(); iter8!=textdisplayArray.end(); iter8++) {
            if (textdisplayArray[counter].destroy == true) {
                textdisplayArray.erase(iter8);
                break;
            }

            counter++;
        }

        //Delete PickUp Items
        counter=0;
        for(iter11=pickupArray.begin(); iter11!=pickupArray.end(); iter11++){
            if(pickupArray[counter].destroy==true){
                pickupArray.erase(iter11);
                break;
            }
            counter++;
        }

        //Player View
        window.setView(view1);
        view1.setCenter(player.rect.getPosition());

        //Draw Wall
        counter=0;
        for(iter15=wallArray.begin(); iter15!=wallArray.end(); iter15++){
            wallArray[counter].update();
            window.draw(wallArray[counter].sprite);
            counter++;
        }

        //Draw Player
        window.draw(player.sprite);

        //Draw Projectiles
        counter=0;
        for(iter=projectileArray.begin(); iter!=projectileArray.end(); iter++){
            projectileArray[counter].update();
            window.draw(projectileArray[counter].sprite);

            counter++;
        }

        //Random Generate Monster //FIXME: appaiono cose strane (grafica)
        monsterRandom=Random::generateRandom(2);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Y)){
            if(monsterRandom==1) {
                monster1.rect.setPosition(Random::generateRandom(window.getSize().x), Random::generateRandom(window.getSize().y));
                monsterArray.push_back(monster1);
            }
            if(monsterRandom==2){
                monster2.rect.setPosition(Random::generateRandom(window.getSize().x), Random::generateRandom(window.getSize().y));
                monsterArray.push_back(monster2);
            }
        }


        //Draw Monster
        counter=0;
        for(iter4=monsterArray.begin(); iter4!=monsterArray.end(); iter4++){
            monsterArray[counter].updateMovement();
            monsterArray[counter].update();
            window.draw(monsterArray[counter].sprite);
            counter++;
        }


        //Draw Text non mi ricordo più cos'è ?????????????????? FIXME: cos'è
        counter=0;
        for(iter8=textdisplayArray.begin(); iter8!=textdisplayArray.end(); iter8++){

            textdisplayArray[counter].update();
            window.draw(textdisplayArray[counter].text);

            counter++;
        }

        //Draw PickUp Items
        counter=0;
        for(iter11=pickupArray.begin(); iter11!=pickupArray.end(); iter11++){
            pickupArray[counter].update();
            window.draw(pickupArray[counter].sprite);
            counter++;
        }

        //Gil Text
        text.setPosition(player.rect.getPosition().x-window.getSize().x/2, player.rect.getPosition().y-window.getSize().y/2 + 50);
        text.setString("Gil:"+to_string(player.gil));
        window.draw(text);

        //Player HP Text
        textHP.setString("HP:" + to_string(player.hp) + "/" + to_string(player.maxHP));
        textHP.setPosition(player.rect.getPosition().x - window.getSize().x/2, player.rect.getPosition().y - window.getSize().y/2);
        window.draw(textHP);

        window.display();
    }
    return EXIT_SUCCESS;
}

