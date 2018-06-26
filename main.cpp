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

using namespace std;

int main() {

    //Variables
    srand(time(NULL));
    int counter = 0;
    int counter2 = 0;
    sf::Clock clock;
    sf::Clock clock2;
    sf::Clock clock3;
    int food;
    int myRandom;
    int monsterRandom;
    bool start=false;

    //create the main window
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "GAME_PROVA3");
    window.setFramerateLimit(60);

    //View
    sf::View view1(sf::FloatRect(200, 200, 300, 200));
    view1.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
    view1.setCenter(sf::Vector2f(view1.getSize().x / 2, view1.getSize().y / 2));
    window.setView(view1);

    GameCharacter player(window.getPosition().x / 2 + 540, window.getPosition().y / 2 + 1400, 10, 50, 50,
                         GCharacters::girl);

    //set the icon
    sf::Image icon;
    if (!icon.loadFromFile("../RisorseSprite/videogamepad.png"))
        return EXIT_FAILURE;
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    //Music
    Sound sound;
    sound.loadSound();
    sound.music.play();
    sound.music.setLoop(true);

    //START
    sf::Sprite windowStart;
    sf::Sprite title;
    sf::Texture startTexture;
    sf::Texture titleTexture;
    if (!startTexture.loadFromFile("../RisorseSprite/forest.jpg"))
        return EXIT_FAILURE;
    if (!titleTexture.loadFromFile("../RisorseSprite/title.png"))
        return EXIT_FAILURE;
    title.setPosition(-240, -400);
    title.setTexture(titleTexture);
    windowStart.setPosition(-1270, -600);
    windowStart.setTexture(startTexture);

    //GAME OVER
    sf::Sprite gameover;
    sf::Texture gameoverTexture;
    if (!gameoverTexture.loadFromFile("../RisorseSprite/gameover3.png"))
        return EXIT_FAILURE;
    gameover.setPosition(-270, -400);
    gameover.setTexture(gameoverTexture);


    //Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile("../RisorseFont/pokemon.ttf"))
        return EXIT_FAILURE;
    sf::Font font2;
    if (!font2.loadFromFile("../RisorseFont/OldLondon.ttf"))
        return EXIT_FAILURE;

    sf::Text startText("Press BACKSPACE to start!", font2, 70);
    startText.setPosition(-400, 0);
    sf::Text text("Gil", font, 25);
    text.setPosition(0, 0);
    sf::Text textHP("HP", font, 25);
    sf::Text victory("VICTORY!", font2, 150);
    victory.setPosition(-330, -150);

    player.loadTexture();

    //Projectile Vector Array
    vector<Projectile>::const_iterator iter;
    vector<Projectile> projectileArray;

    //Projectile Object
    Projectile projectile1;
    projectile1.loadTexture();

    //Monster Vector Array
    vector<Monster>::const_iterator iter4;
    vector<Monster> monsterArray;

    //Monster Object BAT
    Monster monster1(Random::generateRandom(window.getSize().x), Random::generateRandom(window.getSize().y), 5, 30,
                     Monsters::bat);
    monster1.rect.setPosition(400, 200);
    monsterArray.push_back(monster1);
    monster1.loadTexture();

    //Monster Object RAT
    Monster monster2(Random::generateRandom(window.getSize().x), Random::generateRandom(window.getSize().y), 5, 30,
                     Monsters::rat);
    monster2.rect.setPosition(400, 200);
    monsterArray.push_back(monster2);
    monster2.loadTexture();

    //Monster Boss
    Monster boss(window.getPosition().x / 2 + 540, window.getPosition().y / 2 + 100, 20, 200, Monsters::boss);
    boss.loadTexture();

    //Text Vector Array
    vector<TextDisplay>::const_iterator iter8;
    vector<TextDisplay> textdisplayArray;

    //Text Object
    TextDisplay textdisplay1;
    textdisplay1.text.setFont(font);

    //PickUp Vector Array
    vector<PickUp>::const_iterator iter11;
    vector<PickUp> pickupArray;

    //PickUp Object
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
    Map map(48, 48, TileEnum::grass);
    Map wall(48, 48, TileEnum::grass);
    Map road(48, 48, TileEnum::road);
    Map flower(48, 48, TileEnum::flower1);
    Map bossRoom(48, 48, TileEnum::bossRoom);

    grass.loadTexture();
    flower.loadTexture();
    map.loadTexture();
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
            window.draw(windowStart);
            window.draw(title);
            window.draw(startText);

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
                start=true;
        }

        if(start==true) {
            if (player.hp <= 0) {
                view1.setCenter(0, 0);
                window.setView(view1);
                window.draw(gameover);
            } else if (boss.hp <= 0) {
                view1.setCenter(0, 0);
                window.setView(view1);
                window.draw(windowStart);
                window.draw(victory);
            } else {

                sf::Time elapsed1 = clock.getElapsedTime();
                sf::Time elapsed2 = clock2.getElapsedTime();
                sf::Time elapsed3 = clock3.getElapsedTime();

                window.draw(grass1);
                window.draw(grass2);
                window.draw(grass3);
                window.draw(grass4);
                window.draw(grass5);

                grass.drawGrass(&window);
                flower.drawFlower(&window);
                road.drawRoad(&window);

                //Door
                if (door1.isOpen == false) {
                    window.draw(door1.sprite);
                }
                if (door1.isOpen == false) {
                    window.draw(door2.sprite);
                }
                if (door1.isOpen == false) {
                    window.draw(door3.sprite);
                }
                door1.update(&player);
                door2.update(&player);
                door3.update(&player);

                //Draw Wall
                // wall.drawWall(&window, &player, &monsterArray);

                player.update();

                //Player Movement
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                    player.updateMovement(Direction::up);
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                    player.updateMovement(Direction::down);
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                    player.updateMovement(Direction::left);
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                    player.updateMovement(Direction::right);

                //Fire Missle (Space Bar)
                if (elapsed1.asSeconds() >= 0.5) {
                    clock.restart();
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {

                        sound.soundShot.play();

                        //PowerUp Attack
                        if (player.powerUpLevel == true) {
                            projectile1.rect.setPosition(player.rect.getPosition().x, player.rect.getPosition().y);
                            projectile1.direction = player.direction;
                            projectileArray.push_back(projectile1);

                            projectile1.rect.setPosition(player.rect.getPosition().x + Random::generateRandom(50),
                                                         player.rect.getPosition().y + Random::generateRandom(50));
                            projectile1.direction = player.direction;
                            projectileArray.push_back(projectile1);

                            projectile1.rect.setPosition(player.rect.getPosition().x + Random::generateRandom(50),
                                                         player.rect.getPosition().y + Random::generateRandom(50));
                            projectile1.direction = player.direction;
                            projectileArray.push_back(projectile1);
                        } else if (player.novaAttack == true) {
                            projectile1.rect.setPosition(player.rect.getPosition().x + player.rect.getSize().x / 2 -
                                                         projectile1.rect.getSize().x / 2,
                                                         player.rect.getPosition().y + player.rect.getSize().y / 2 -
                                                         projectile1.rect.getSize().y / 2);
                            projectile1.direction = Direction::up;
                            projectileArray.push_back(projectile1);

                            projectile1.rect.setPosition(player.rect.getPosition().x + player.rect.getSize().x / 2 -
                                                         projectile1.rect.getSize().x / 2,
                                                         player.rect.getPosition().y + player.rect.getSize().y / 2 -
                                                         projectile1.rect.getSize().y / 2);
                            projectile1.direction = Direction::down;
                            projectileArray.push_back(projectile1);

                            projectile1.rect.setPosition(player.rect.getPosition().x + player.rect.getSize().x / 2 -
                                                         projectile1.rect.getSize().x / 2,
                                                         player.rect.getPosition().y + player.rect.getSize().y / 2 -
                                                         projectile1.rect.getSize().y / 2);
                            projectile1.direction = Direction::left;
                            projectileArray.push_back(projectile1);

                            projectile1.rect.setPosition(player.rect.getPosition().x + player.rect.getSize().x / 2 -
                                                         projectile1.rect.getSize().x / 2,
                                                         player.rect.getPosition().y + player.rect.getSize().y / 2 -
                                                         projectile1.rect.getSize().y / 2);
                            projectile1.direction = Direction::right;
                            projectileArray.push_back(projectile1);
                        } else {
                            //Normal Attack
                            projectile1.rect.setPosition(player.rect.getPosition().x, player.rect.getPosition().y);
                            projectile1.direction = player.direction;
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
                        textdisplay1.text.setString(to_string(projectileArray[counter].attackDamage));
                        textdisplay1.text.setPosition(boss.rect.getPosition().x + boss.rect.getSize().x / 2,
                                                      boss.rect.getPosition().y - boss.rect.getSize().y / 2);
                        textdisplayArray.push_back(textdisplay1);
                        boss.hp -= projectileArray[counter].attackDamage;

                        if (boss.hp <= 0)
                            boss.alive = false;
                    }
                    for (iter4 = monsterArray.begin(); iter4 != monsterArray.end(); iter4++) {
                        if (projectileArray[counter].rect.getGlobalBounds().intersects(
                                monsterArray[counter2].rect.getGlobalBounds())) {
                            projectileArray[counter].destroy = true;

                            sound.soundCollision.play();

                            //Text Display
                            textdisplay1.text.setString(to_string(projectileArray[counter].attackDamage));
                            textdisplay1.text.setPosition(monsterArray[counter2].rect.getPosition().x +
                                                          monsterArray[counter2].rect.getSize().x / 2,
                                                          monsterArray[counter2].rect.getPosition().y -
                                                          monsterArray[counter2].rect.getSize().y / 2);
                            textdisplayArray.push_back(textdisplay1);

                            monsterArray[counter2].hp -= projectileArray[counter].attackDamage;

                            if (monsterArray[counter2].hp <= 0)
                                monsterArray[counter2].alive = false;
                        }
                        counter2++;
                    }
                    counter++;
                }

                //Monster Collides with Player (player takes damage)
                if (elapsed2.asSeconds() >= 0.5) {
                    clock2.restart();
                    counter = 0;
                    if (player.rect.getGlobalBounds().intersects(boss.rect.getGlobalBounds())) {
                        sound.soundPDamage.play();
                        //Text Display
                        textdisplay1.text.setString(to_string(boss.attackDamage));
                        textdisplay1.text.setPosition(player.rect.getPosition().x + player.rect.getSize().x / 2,
                                                      player.rect.getPosition().y - player.rect.getSize().y / 2);
                        textdisplayArray.push_back(textdisplay1);
                        player.hp -= boss.attackDamage;
                        player.powerUpLevel = false;
                        player.novaAttack = false;
                    }
                    for (iter4 = monsterArray.begin(); iter4 != monsterArray.end(); iter4++) {
                        if (player.rect.getGlobalBounds().intersects(monsterArray[counter].rect.getGlobalBounds())) {
                            sound.soundPDamage.play();
                            //Text Display
                            textdisplay1.text.setString(to_string(monsterArray[counter].attackDamage));
                            textdisplay1.text.setPosition(player.rect.getPosition().x + player.rect.getSize().x / 2,
                                                          player.rect.getPosition().y - player.rect.getSize().y / 2);
                            textdisplayArray.push_back(textdisplay1);
                            player.hp -= monsterArray[counter].attackDamage;
                            player.powerUpLevel = false;
                            player.novaAttack = false;
                        }
                        counter++;
                    }
                }

                /*  //Monster Collides with Wall
                  counter2=0;
                  for (iter4 = monsterArray.begin(); iter4 != monsterArray.end(); iter4++) {
                      counter = 0;
                      for (wall.iter = wall.wallBuffer.begin(); wall.iter != wall.wallBuffer.end(); wall.iter++) {
                          if ( monsterArray[counter2].rect.getGlobalBounds().intersects(wall.wallBuffer[counter]->rect.getGlobalBounds())) {
                              monsterArray[counter].monsterWall();
                          }
                          counter++;
                      }
                      counter2++;
                  }*/

                //Player Collides with PickUp Item
                counter = 0;
                for (iter11 = pickupArray.begin(); iter11 != pickupArray.end(); iter11++) {
                    if (player.rect.getGlobalBounds().intersects(pickupArray[counter].rect.getGlobalBounds())) {
                        if (pickupArray[counter].isCoin == true) {
                            //sound.soundCoin.setVolume(100);
                            sound.soundCoin.play();
                            player.wallet += pickupArray[counter].coinValue;
                            pickupArray[counter].destroy = true;
                        }
                        if (pickupArray[counter].inShop == true) {
                            if (player.wallet >= pickupArray[counter].cost) {
                                player.wallet -= pickupArray[counter].cost;
                                if (pickupArray[counter].isKey == true) {
                                    sound.soundCoin.play();
                                    player.key = true;
                                    door1.open = true;
                                    door2.open = true;
                                    door3.open = true;
                                    pickupArray[counter].destroy = true;
                                    cout << "key collected" << endl;
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
                            sound.soundCoin.setVolume(100);
                            sound.soundCoin.play();
                            player.hp += pickupArray[counter].foodValue;
                            pickupArray[counter].destroy = true;
                        }
                    }
                    counter++;
                }

                //Delete Dead Monsters
                counter = 0;
                monsterRandom = Random::generateRandom(2);
                //monster1.rect.setPosition(window.getPosition().x / 2 + 640, window.getPosition().y / 2 + 1400);
                // monster2.rect.setPosition(window.getPosition().x / 2 + 440, window.getPosition().y / 2 + 1400);
                for (iter4 = monsterArray.begin(); iter4 != monsterArray.end(); iter4++) {
                    myRandom = Random::generateRandom(4);
                    if (monsterArray[counter].alive == false) {
                        if (monsterRandom == 1)
                            monsterArray.push_back(monster1);
                        if (monsterRandom == 2)
                            monsterArray.push_back(monster2);
                        //Drop Coin
                        if (myRandom == 1) { //voglio più monete e meno attacchi speciali
                            pickup1.isCoin = true;
                            pickup1.isPowerUp = false;
                            pickup1.isNovaAttack = false;
                            pickup1.isFood = false;
                            pickup1.sprite.setTextureRect(sf::IntRect(13 * 24, 12 * 24, 24, 24));
                            pickup1.rect.setPosition(monsterArray[counter].rect.getPosition());
                            pickupArray.push_back((pickup1));
                        }

                        //Drop Food
                        if (myRandom == 2) {
                            pickup1.isFood = true;
                            pickup1.isNovaAttack = false;
                            pickup1.isPowerUp = false;
                            pickup1.isCoin = false;
                            food = Random::generateRandom0(10);
                            pickup1.sprite.setTextureRect(sf::IntRect(food * 24, 10 * 24, 24, 24));
                            pickup1.rect.setPosition(monsterArray[counter].rect.getPosition());
                            pickupArray.push_back(pickup1);
                        }

                        //Drop PowerUp
                        if (myRandom == 3) {
                            pickup1.isPowerUp = true;
                            pickup1.isCoin = false;
                            pickup1.isFood = false;
                            pickup1.isNovaAttack = false;
                            pickup1.sprite.setTextureRect(sf::IntRect(4 * 24, 13 * 24, 24, 24));
                            pickup1.rect.setPosition(monsterArray[counter].rect.getPosition());
                            pickupArray.push_back(pickup1);
                            player.powerUpLevel = true;
                        }

                        //Drop NovaAttack
                        if (myRandom == 4) {
                            pickup1.isNovaAttack = true;
                            pickup1.isPowerUp = false;
                            pickup1.isCoin = false;
                            pickup1.isFood = false;
                            pickup1.sprite.setTextureRect(sf::IntRect(24, 13 * 24, 24, 24));
                            pickup1.rect.setPosition(monsterArray[counter].rect.getPosition());
                            pickupArray.push_back(pickup1);
                            player.novaAttack = true;
                        }

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
                    monsterArray[counter].updateMovement();
                    monsterArray[counter].update();
                    window.draw(monsterArray[counter].sprite);
                    counter++;
                }
                boss.updateMovement();
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

                //Draw Gil Text
                text.setPosition(player.rect.getPosition().x - window.getSize().x / 2,
                                 player.rect.getPosition().y - window.getSize().y / 2 + 50);
                text.setString("Coin:" + to_string(player.wallet));
                window.draw(text);

                //Draw Player HP Text
                textHP.setString("HP:" + to_string(player.hp) + "/" + to_string(player.maxHP));
                textHP.setPosition(player.rect.getPosition().x - window.getSize().x / 2,
                                   player.rect.getPosition().y - window.getSize().y / 2);
                window.draw(textHP);

            }
        }

        window.display();
    }
    return EXIT_SUCCESS;

}

