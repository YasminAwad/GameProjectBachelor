#include <iostream>
#include <SFML/Graphics.hpp>

#include "GameCharacter.h"
#include "Graphic.h"
#include "Projectile.h"
#include "Monster.h"
#include "Random.h"
#include "TextDisplay.h"

using namespace std;

int main() {

    //Variables
    srand(time(NULL));
    int counter;
    int counter2;
    sf::Clock clock;
    sf::Clock clock2;
    sf::Clock clock3;

    //create the main window
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "GAME_PROVA3");

    window.setFramerateLimit(60);

    Graphic graphic;

    GameCharacter player(window.getPosition().x/2, window.getPosition().y/2, 10, 0, 50, 50, GCharacters::girl);

    //set the icon
    sf::Image icon;
    if (!icon.loadFromFile("../RisorseSprite/videogamepad.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    //Create a graphical text to display
    sf::Font font;
    if(!font.loadFromFile("../RisorseFont/pokemon.ttf")){
        return EXIT_FAILURE;
    }

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
    player.setCharacter();

    //Projectile Vector Array
    vector<Projectile>::const_iterator iter;
    vector <Projectile> projectileArray;

    //Projectile Object
    Projectile projectile1;
    projectile1.loadTexture();

    //Monster Vector Array
    vector<Monster>::const_iterator iter4;
    vector<Monster> monsterArray;

    //Monster Object
    Monster monster1;
    monster1.rect.setPosition(400,200);
    monsterArray.push_back(monster1);
    monster1.loadTexture();

    //Text Vector Array
    vector<TextDisplay>::const_iterator iter8;
    vector<TextDisplay> textdisplayArray;

    //Text Object
    TextDisplay textdisplay1;
    textdisplay1.text.setFont(font);



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

        //window.draw(forest);

        player.update();
        player.updateMovement();

        //Fire Missle (Space Bar)
        if(elapsed1.asSeconds()>=0.5){
            clock.restart();
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                projectile1.rect.setPosition(player.rect.getPosition().x, player.rect.getPosition().y);
                projectile1.direction = player.direction;
                projectileArray.push_back(projectile1);
            }
        }


        //Projectiles Collides with Monster
        counter=0;
        for(iter=projectileArray.begin(); iter!=projectileArray.end(); iter++){
            counter2=0;
            for(iter4=monsterArray.begin(); iter4!=monsterArray.end(); iter4++){
                if(projectileArray[counter].rect.getGlobalBounds().intersects(monsterArray[counter2].rect.getGlobalBounds())){
                    projectileArray[counter].destroy=true;

                    //Text Display
                    textdisplay1.text.setString(to_string(projectileArray[counter].attackDamage));
                    textdisplay1.text.setPosition(monsterArray[counter2].rect.getPosition().x + monsterArray[counter2].rect.getSize().x/2, monsterArray[counter2].rect.getPosition().y - monsterArray[counter2].rect.getSize().y/2);
                    textdisplayArray.push_back(textdisplay1);

                    monsterArray[counter2].hp-=projectileArray[counter].attackDamage;

                    if(monsterArray[counter2].hp<=0){
                        monsterArray[counter2].alive=false;
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

                    //Text Display
                    textdisplay1.text.setString(to_string(monsterArray[counter].attackDamage));
                    textdisplay1.text.setPosition(player.rect.getPosition().x + player.rect.getSize().x/2, player.rect.getPosition().y - player.rect.getSize().y/2);
                    textdisplayArray.push_back(textdisplay1);

                    player.hp -= monsterArray[counter].attackDamage;
                }
                counter++;
            }
        }

        //Delete Dead Monsters
        counter=0;
        for(iter4=monsterArray.begin(); iter4!=monsterArray.end(); iter4++){
            if(monsterArray[counter].alive==false){
                monsterArray.erase(iter4);
                break;
            }
            counter++;
        }

        //Delete Projectiles
        counter=0;
        for(iter=projectileArray.begin(); iter!=projectileArray.end(); iter++){
            if(projectileArray[counter].destroy==true){
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

        //Draw Player
        window.draw(player.sprite);

        //Draw Projectiles
        counter=0;
        for(iter=projectileArray.begin(); iter!=projectileArray.end(); iter++){
            projectileArray[counter].update();
            window.draw(projectileArray[counter].sprite);

            counter++;
        }

        //Random Generate Monster
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Y)){
            rect.setPosition(Random::generateRandom(window.getSize().x), Random::generateRandom(window.getSize().y));
            monsterArray.push_back(monster1);

        }


        //Draw Monster
        counter=0;
        for(iter4=monsterArray.begin(); iter4!=monsterArray.end(); iter4++){
            monsterArray[counter].updateMovement();
            monsterArray[counter].update();
            window.draw(monsterArray[counter].sprite);
            counter++;
        }

        //Draw Text
        counter=0;
        for(iter8=textdisplayArray.begin(); iter8!=textdisplayArray.end(); iter8++){

            textdisplayArray[counter].update();
            window.draw(textdisplayArray[counter].text);

            counter++;
        }

        window.display();
    }
    return EXIT_SUCCESS;
}

