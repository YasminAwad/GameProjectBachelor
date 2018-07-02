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
#include "Map.h"
#include "MapObjects.h"
#include "LoadDisplay.h"

using namespace std;

int main() {
again:
    //Variables
    srand(time(NULL));
    int counter = 0;
    int counter2 = 0;
    sf::Clock clock;
    sf::Clock clock2;
    sf::Clock clock3;
    int myRandom;
    int monsterRandom;
    bool start=false;
    bool choiceWindow=false;
    bool musicVictory=false;
    bool musicGameOver=false;

    //create the main window
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "GAME_PROVA3");
    window.setFramerateLimit(60);

    //View
    sf::View view1(sf::FloatRect(200, 200, 300, 200));
    view1.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
    view1.setCenter(sf::Vector2f(view1.getSize().x / 2, view1.getSize().y / 2));
    window.setView(view1);

    //Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile("../RisorseSprite/videogamepad.png"))
        return EXIT_FAILURE;
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    //Music
    Sound sound;
    sound.loadSound();
    sound.music.play();
    sound.music.setLoop(true);
    sound.soundCoin.setVolume(100);

    //Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile("../RisorseFont/pokemon.ttf"))
        return EXIT_FAILURE;
    sf::Font font2;
    if (!font2.loadFromFile("../RisorseFont/Augusta.ttf"))
        return EXIT_FAILURE;
    sf::Font font3;
    if (!font3.loadFromFile("../RisorseFont/coolvetica.ttf"))
        return EXIT_FAILURE;

    LoadDisplay display;
    display.setDisplay(font2);

    sf::Text textStart("Press BACKSPACE to start!", font2, 70);
    textStart.setPosition(-400, -100);
    sf::Text istruction("Move: Arrows \nFireBall: SpaceBar\nKill monsters! Pickup life, coins and special-powers!\nBuy the KEY and KILL the BOSS!\n\nBy Yasmin Awad", font3, 40);
    istruction.setPosition(-400, 100);
    sf::Text choicePlayerText("PRESS B  PRESS G", font2, 100);
    choicePlayerText.setPosition(-470, 200);
    choicePlayerText.setColor(sf::Color::Cyan);
    sf::Text victoryText("VICTORY", font2, 150);
    victoryText.setPosition(-330, -150);
    sf::Text textGil("Gil", font, 25);
    sf::Text textHP("HP", font, 25);
    sf::Text textIstruction("I:istruction", font, 25);

    //Player
    GameCharacter player(window.getPosition().x / 2 + 540, window.getPosition().y / 2 + 1400, 10, 50, 50, GCharacters::boy);
    player.loadTexture();

    //Projectile Vector Array
    vector<Projectile>::const_iterator iter;
    vector<Projectile> projectileArray;
    Projectile projectile1;
    projectile1.loadTexture();

    //Monster Vector Array
    vector<Monster>::const_iterator iter4;
    vector<Monster> monsterArray;
    Monster monster1(100,1300, 5, 35, Monsters::bat);
    Monster monster2(1300, 1300, 5, 35, Monsters::rat);
    monster1.loadTexture();
    monster2.loadTexture();

    //MonsterFactory
    for(int size=1; size<6; size++){
        monsterArray.push_back(monster1);
        monsterArray.push_back(monster2);
    }

    monsterArray[0].rect.setPosition(100, 100);
    monsterArray[1].rect.setPosition(200,400);
    monsterArray[2].rect.setPosition(1300,200);
    monsterArray[3].rect.setPosition(1400,500);
    monsterArray[4].rect.setPosition(300,1100);
    monsterArray[5].rect.setPosition(500,1200);
    monsterArray[6].rect.setPosition(1200,1000);
    monsterArray[7].rect.setPosition(1000,1100);
    monsterArray[8].rect.setPosition(100, 1300);
    monsterArray[9].rect.setPosition(1300, 1300);

    //Monster Boss
    Monster boss(window.getPosition().x / 2 + 540, window.getPosition().y / 2 + 100, 20, 200, Monsters::boss);
    boss.loadTexture();
    boss.setMovementSpeed(5);

    //Text Vector Array
    vector<TextDisplay>::const_iterator iter8;
    vector<TextDisplay> textdisplayArray;
    TextDisplay textdisplay1;
    textdisplay1.text.setFont(font);

    //PickUp Vector Array
    vector<PickUp>::const_iterator iter11;
    vector<PickUp> pickupArray;
    PickUp pickup1;
    pickupArray.push_back(pickup1);
    pickup1.loadTexture();
    pickup1.text.setFont(font);
    pickup1.text.setCharacterSize(17);
    pickup1.text.setColor(sf::Color::Black);

    //Key
    pickup1.cost = 5;
    pickup1.text.setString("Costs " + to_string(pickup1.cost));
    pickup1.inShop = true;
    pickup1.isKey = true;
    pickup1.isCoin = false;
    pickup1.isFood = false;
    pickup1.isNovaAttack = false;
    pickup1.isPowerUp = false;
    pickup1.sprite.setTextureRect(sf::IntRect(24 * 3, 24 * 5, 24, 24));

    pickup1.rect.setPosition(100, 780);
    pickupArray.push_back(pickup1);
    pickup1.inShop = false;

    //Map
    sf::Sprite grass1;
    sf::Texture grassTexture;
    if (!grassTexture.loadFromFile("../RisorseSprite/grasstype.png"))
        return EXIT_FAILURE;
    grass1.setPosition(-470, -500);
    grass1.setTexture(grassTexture);
    sf::Sprite grass2;
    grass2.setPosition(519, -500);
    grass2.setTexture(grassTexture);
    sf::Sprite grass3;
    grass3.setPosition(1000, -500);
    grass3.setTexture(grassTexture);
    sf::Sprite grass4;
    grass4.setPosition(-470, 424);
    grass4.setTexture(grassTexture);
    sf::Sprite grass5;
    grass5.setPosition(-470, 1000);
    grass5.setTexture(grassTexture);

    Map grass(65, 65, TileEnum::grass);
    Map wall(48, 48, TileEnum::grass);
    Map road(48, 48, TileEnum::road);
    Map flower1(48, 48, TileEnum::flower1);
    Map flower2(48, 48, TileEnum::flower2);
    Map bossRoom(48, 48, TileEnum::bossRoom);
    grass.loadTexture();
    flower1.loadTexture();
    flower2.loadTexture();
    road.loadTexture();
    wall.loadTexture();

    MapObjects door1(TileEnum::door);
    door1.loadTexture();
    MapObjects door2(TileEnum::door);
    door2.rect.setPosition(770, 450);
    door2.loadTexture();
    MapObjects door3(TileEnum::door);
    door3.rect.setPosition(735, 450);
    door3.loadTexture();


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
        if(start==false){
            view1.setCenter(0, 0);
            window.setView(view1);
            window.draw(display.windowStart.sprite);
            window.draw(display.title.sprite);
            window.draw(textStart);
            window.draw(istruction);

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
                start=true;
        }
        if(start==true) {
            if (choiceWindow == false) {
                window.draw(display.choiceBoy.sprite);
                window.draw(display.choiceGirl.sprite);
                window.draw(choicePlayerText);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {
                    player.gameCharacter = GCharacters::girl;
                    player.sprite.setTextureRect(sf::IntRect(0, 0, 24, 32));
                    choiceWindow = true;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
                    choiceWindow = true;

            } else {
                if (player.getHP() <= 0) {
                    sound.music.stop();
                    view1.setCenter(0, 0);
                    window.setView(view1);
                    window.draw(display.end.sprite);
                    textStart.setPosition(-400, 100);
                    window.draw(textStart);
                    if(musicGameOver==false) {
                        sound.soundGameOver.play();
                        musicGameOver = true;
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
                        goto again;
                    }
                } else if (boss.getHP() <= 0) {
                    sound.music.stop();
                    view1.setCenter(0, 0);
                    window.setView(view1);
                    window.draw(display.windowStart.sprite);
                    window.draw(victoryText);
                    textStart.setPosition(-400, 100);
                    window.draw(textStart);
                    if(musicVictory==false) {
                        sound.soundVictory.play();
                        musicVictory = true;
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
                        goto again;
                    }
                } else {

                    sf::Time elapsed1 = clock.getElapsedTime();
                    sf::Time elapsed2 = clock2.getElapsedTime();

                    window.draw(grass1);
                    window.draw(grass2);
                    window.draw(grass3);
                    window.draw(grass4);
                    window.draw(grass5);
                    grass.drawGrass(&window);
                    flower1.drawFlower1(&window);
                    flower2.drawFlower2(&window);
                    road.drawRoad(&window);

                    //Door
                    if (door1.isOpen == false) {
                        if (door2.isOpen == false) {
                            if (door3.isOpen == false) {
                                window.draw(door1.sprite);
                            }
                        }
                    }
                    if (door1.isOpen == false) {
                        if (door2.isOpen == false) {
                            if (door3.isOpen == false) {
                                window.draw(door2.sprite);
                            }
                        }
                    }
                    if (door1.isOpen == false) {
                        if (door2.isOpen == false) {
                            if (door3.isOpen == false) {
                                window.draw(door3.sprite);
                            }
                        }
                    }
                    door1.update(&player);
                    door2.update(&player);
                    door3.update(&player);

                    //Draw Wall
                    wall.drawWall(&window, &player);

                    //Player Movement
                    player.update();
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                        player.updateMovement(Direction::up);
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                        player.updateMovement(Direction::down);
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                        player.updateMovement(Direction::left);
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                        player.updateMovement(Direction::right);

                    //Projectiles (Space Bar)
                    if (elapsed1.asSeconds() >= 0.5) {
                        clock.restart();
                        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                            sound.soundShot.play();

                            //PowerUp Attack
                            if (player.powerUpLevel == true) {
                                projectile1.rect.setPosition(player.rect.getPosition().x, player.rect.getPosition().y);
                                projectile1.setDirection(player.getDirection());
                                projectileArray.push_back(projectile1);

                                projectile1.rect.setPosition(player.rect.getPosition().x + Random::generateRandom(50),
                                                             player.rect.getPosition().y + Random::generateRandom(50));
                                projectile1.setDirection(player.getDirection());
                                projectileArray.push_back(projectile1);

                                projectile1.rect.setPosition(player.rect.getPosition().x + Random::generateRandom(50),
                                                             player.rect.getPosition().y + Random::generateRandom(50));
                                projectile1.setDirection(player.getDirection());
                                projectileArray.push_back(projectile1);
                            } else if (player.novaAttack == true) {
                                projectile1.rect.setPosition(player.rect.getPosition().x + player.rect.getSize().x / 2 -
                                                             projectile1.rect.getSize().x / 2,
                                                             player.rect.getPosition().y + player.rect.getSize().y / 2 -
                                                             projectile1.rect.getSize().y / 2);
                                projectile1.setDirection(Direction::up);
                                projectileArray.push_back(projectile1);

                                projectile1.rect.setPosition(player.rect.getPosition().x + player.rect.getSize().x / 2 -
                                                             projectile1.rect.getSize().x / 2,
                                                             player.rect.getPosition().y + player.rect.getSize().y / 2 -
                                                             projectile1.rect.getSize().y / 2);
                                projectile1.setDirection(Direction::down);
                                projectileArray.push_back(projectile1);

                                projectile1.rect.setPosition(player.rect.getPosition().x + player.rect.getSize().x / 2 -
                                                             projectile1.rect.getSize().x / 2,
                                                             player.rect.getPosition().y + player.rect.getSize().y / 2 -
                                                             projectile1.rect.getSize().y / 2);
                                projectile1.setDirection(Direction::left);
                                projectileArray.push_back(projectile1);

                                projectile1.rect.setPosition(player.rect.getPosition().x + player.rect.getSize().x / 2 -
                                                             projectile1.rect.getSize().x / 2,
                                                             player.rect.getPosition().y + player.rect.getSize().y / 2 -
                                                             projectile1.rect.getSize().y / 2);
                                projectile1.setDirection(Direction::right);
                                projectileArray.push_back(projectile1);
                            } else {
                                //Normal Attack
                                projectile1.rect.setPosition(player.rect.getPosition().x, player.rect.getPosition().y);
                                projectile1.setDirection(player.getDirection());
                                projectileArray.push_back(projectile1);
                            }
                        }
                    }

                    //Projectiles Collides with Monster
                    counter = 0;
                    for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++) {
                        counter2 = 0;
                        if (projectileArray[counter].rect.getGlobalBounds().intersects(boss.rect.getGlobalBounds())) {
                            projectileArray[counter].destroy = true;
                            sound.soundCollision.play();
                            //Text Display
                            textdisplay1.text.setString(to_string(projectileArray[counter].getAttackDamage()));
                            textdisplay1.text.setPosition(boss.rect.getPosition().x + boss.rect.getSize().x / 2,
                                                          boss.rect.getPosition().y - boss.rect.getSize().y / 2);
                            textdisplayArray.push_back(textdisplay1);
                            boss.setHP(boss.getHP() - projectileArray[counter].getAttackDamage());

                            boss.setAggroed(true);

                            if (boss.getHP() < 50) {
                                boss.setFlee();
                                boss.setMovementSpeed(3);
                            }

                            if (boss.getHP() <= 0)
                                boss.alive = false;
                        }
                        for (iter4 = monsterArray.begin(); iter4 != monsterArray.end(); iter4++) {
                            if (projectileArray[counter].rect.getGlobalBounds().intersects(
                                    monsterArray[counter2].rect.getGlobalBounds())) {
                                projectileArray[counter].destroy = true;

                                sound.soundCollision.play();

                                //Text Display
                                textdisplay1.text.setString(to_string(projectileArray[counter].getAttackDamage()));
                                textdisplay1.text.setPosition(monsterArray[counter2].rect.getPosition().x +
                                                              monsterArray[counter2].rect.getSize().x / 2,
                                                              monsterArray[counter2].rect.getPosition().y -
                                                              monsterArray[counter2].rect.getSize().y / 2);
                                textdisplayArray.push_back(textdisplay1);

                                monsterArray[counter2].setHP(monsterArray[counter2].getHP() - projectileArray[counter].getAttackDamage());

                                monsterArray[counter2].setFlee();
                                if (monsterArray[counter2].getHP() <= 0)
                                    monsterArray[counter2].alive = false;
                            }
                            counter2++;
                        }
                        counter++;
                    }

                    //Projectiles Collides with Wall
                    counter = 0;
                    for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++) {
                        counter2 = 0;
                        for (wall.iter = wall.wallBuffer.begin(); wall.iter != wall.wallBuffer.end(); wall.iter++) {
                            if (projectileArray[counter].rect.getGlobalBounds().intersects(
                                    wall.wallBuffer[counter2]->rect.getGlobalBounds())) {
                                if (wall.wallBuffer[counter2]->isWalkable == false) {
                                    projectileArray[counter].destroy = true;
                                    //sound.soundCollision.play();
                                }
                            }
                            counter2++;
                        }
                        counter++;
                    }

                    //Monster Collides with Wall
                    counter = 0;
                    for (iter4 = monsterArray.begin(); iter4 != monsterArray.end(); iter4++) {
                        counter2 = 0;
                        for (wall.iter = wall.wallBuffer.begin(); wall.iter != wall.wallBuffer.end(); wall.iter++) {
                            if (monsterArray[counter].rect.getGlobalBounds().intersects(
                                    wall.wallBuffer[counter2]->rect.getGlobalBounds())) {
                                if (wall.wallBuffer[counter2]->isWalkable == false) {
                                    monsterArray[counter].monsterWall();
                                }
                            }
                            counter2++;
                        }
                        counter++;
                    }

                    //Boss Collides with Wall
                    counter2 = 0;
                    for (wall.iter = wall.wallBuffer.begin(); wall.iter != wall.wallBuffer.end(); wall.iter++) {
                        if (boss.rect.getGlobalBounds().intersects(wall.wallBuffer[counter2]->rect.getGlobalBounds())) {
                            if (wall.wallBuffer[counter2]->isWalkable == false) {
                                boss.monsterWall();
                            }
                        }
                        counter2++;
                    }

                    //Monster Collides with Player (player takes damage)
                    if (elapsed2.asSeconds() >= 0.5) {
                        clock2.restart();
                        counter = 0;
                        if (player.rect.getGlobalBounds().intersects(boss.rect.getGlobalBounds())) {
                            sound.soundPDamage.play();
                            //Text Display
                            textdisplay1.text.setString(to_string(boss.getDamage()));
                            textdisplay1.text.setPosition(player.rect.getPosition().x + player.rect.getSize().x / 2,
                                                          player.rect.getPosition().y - player.rect.getSize().y / 2);
                            textdisplayArray.push_back(textdisplay1);
                            player.setHP(player.getHP() -  boss.getDamage());
                            player.powerUpLevel = false;
                            player.novaAttack = false;
                        }
                        for (iter4 = monsterArray.begin(); iter4 != monsterArray.end(); iter4++) {
                            if (player.rect.getGlobalBounds().intersects(
                                    monsterArray[counter].rect.getGlobalBounds())) {
                                sound.soundPDamage.play();
                                //Text Display
                                textdisplay1.text.setString(to_string(monsterArray[counter].getDamage()));
                                textdisplay1.text.setPosition(player.rect.getPosition().x + player.rect.getSize().x / 2,
                                                              player.rect.getPosition().y -
                                                              player.rect.getSize().y / 2);
                                textdisplayArray.push_back(textdisplay1);
                                player.setHP(player.getHP() - monsterArray[counter].getDamage());
                                player.powerUpLevel = false;
                                player.novaAttack = false;
                            }
                            counter++;
                        }
                    }

                    //Player Collides with PickUp Item
                    counter = 0;
                    for (iter11 = pickupArray.begin(); iter11 != pickupArray.end(); iter11++) {
                        if (player.rect.getGlobalBounds().intersects(pickupArray[counter].rect.getGlobalBounds())) {
                            if (pickupArray[counter].isCoin == true) {
                                sound.soundCoin.play();
                                player.wallet += pickupArray[counter].coinValue;
                                pickupArray[counter].destroy = true;
                            }
                            if (pickupArray[counter].inShop == true) {
                                if (player.wallet >= pickupArray[counter].cost) {
                                    player.wallet -= pickupArray[counter].cost;
                                    if (pickupArray[counter].isKey == true) {
                                        sound.soundCoin.play();
                                        //player.key = true;
                                        door1.open = true;
                                        door2.open = true;
                                        door3.open = true;
                                        pickupArray[counter].destroy = true;
                                    }
                                }
                            }
                            if (pickupArray[counter].isPowerUp == true) {
                                sound.soundPower.play();
                                player.powerUpLevel = true;
                                player.novaAttack = false;
                                pickupArray[counter].destroy = true;
                            }
                            if (pickupArray[counter].isNovaAttack == true) {
                                sound.soundPower.play();
                                player.powerUpLevel = false;
                                player.novaAttack = true;
                                pickupArray[counter].destroy = true;
                            }
                            if (pickupArray[counter].isFood == true) {
                                sound.soundCoin.play();
                                player.heal(pickupArray[counter].foodValue);
                                pickupArray[counter].destroy = true;
                            }
                        }
                        counter++;
                    }

                    //Delete Dead Monsters
                    counter = 0;
                    monsterRandom = Random::generateRandom(2);
                    for (iter4 = monsterArray.begin(); iter4 != monsterArray.end(); iter4++) {
                        myRandom = Random::generateRandom(4);
                        if (monsterArray[counter].alive == false) {
                            if (monsterRandom == 1)
                                monsterArray.push_back(monster1);
                            if (monsterRandom == 2)
                                monsterArray.push_back(monster2);

                            switch(myRandom){
                                case 1: //Drop Coin
                                    pickup1.dropCoin(monsterArray, counter);
                                    break;
                                case 2: //Drop Food
                                    pickup1.dropFood(monsterArray, counter);
                                    break;
                                case 3: //Drop PowerUp
                                    pickup1.dropPowerUp(monsterArray, counter);
                                    break;
                                case 4: //Drop Nova Attack
                                    pickup1.dropNovaAttack(monsterArray, counter);
                                    break;
                            }
                            pickupArray.push_back((pickup1));

                            monsterArray.erase(iter4);
                            break;
                        }
                        counter++;
                    }

                    //Delete Projectiles
                    counter = 0;
                    for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++) {
                        if (projectileArray[counter].destroy == true) {
                            projectileArray.erase(iter);
                            break;
                        }
                        counter++;
                    }

                    //Delete Text Display
                    counter = 0;
                    for (iter8 = textdisplayArray.begin(); iter8 != textdisplayArray.end(); iter8++) {
                        if (textdisplayArray[counter].destroy == true) {
                            textdisplayArray.erase(iter8);
                            break;
                        }

                        counter++;
                    }

                    //Delete PickUp Items
                    counter = 0;
                    for (iter11 = pickupArray.begin(); iter11 != pickupArray.end(); iter11++) {
                        if (pickupArray[counter].destroy == true) {
                            pickupArray.erase(iter11);
                            break;
                        }
                        counter++;
                    }

                    //Player View
                    window.setView(view1);
                    view1.setCenter(player.rect.getPosition());

                    //Draw Player
                    window.draw(player.sprite);

                    //Draw Projectiles
                    counter = 0;
                    for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++) {
                        projectileArray[counter].update();
                        window.draw(projectileArray[counter].sprite);

                        counter++;
                    }

                    //Draw Monster
                    counter = 0;
                    for (iter4 = monsterArray.begin(); iter4 != monsterArray.end(); iter4++) {
                        monsterArray[counter].updateMovement(&player);
                        monsterArray[counter].update();
                        window.draw(monsterArray[counter].sprite);
                        counter++;
                    }
                    boss.updateMovement(&player);
                    boss.update();
                    window.draw(boss.sprite);



                    //Draw Text (Player Damage)
                    counter = 0;
                    for (iter8 = textdisplayArray.begin(); iter8 != textdisplayArray.end(); iter8++) {

                        textdisplayArray[counter].update();
                        window.draw(textdisplayArray[counter].text);

                        counter++;
                    }

                    //Draw PickUp Items
                    counter = 0;
                    for (iter11 = pickupArray.begin(); iter11 != pickupArray.end(); iter11++) {
                        if (pickupArray[counter].inShop == true) {
                            window.draw(pickupArray[counter].text);
                        }
                        pickupArray[counter].update();
                        window.draw(pickupArray[counter].sprite);
                        counter++;
                    }

                    //Draw Player HP Text
                    textHP.setString("HP:" + to_string(player.getHP()) + "/" + to_string(player.getmaxHP()));
                    textHP.setPosition(player.rect.getPosition().x - window.getSize().x / 2+10,
                                       player.rect.getPosition().y - window.getSize().y / 2+10);
                    window.draw(textHP);

                    //Draw Gil Text
                    textGil.setPosition(player.rect.getPosition().x - window.getSize().x / 2+10,
                                        player.rect.getPosition().y - window.getSize().y / 2 + 60);
                    textGil.setString("Coin:" + to_string(player.wallet));
                    window.draw(textGil);

                    //Draw Istruction Text
                    textIstruction.setPosition(player.rect.getPosition().x - window.getSize().x / 2+10,
                                       player.rect.getPosition().y - window.getSize().y / 2+110);
                    window.draw(textIstruction);

                    istruction.setColor(sf::Color::Black);
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {
                            istruction.setPosition(player.rect.getPosition().x - 400,
                                                   player.rect.getPosition().y + 200);
                            window.draw(istruction);
                    }

                }
            }
        }

        window.display();
    }
    return EXIT_SUCCESS;

}