//
// Created by Yasmin on 26/05/2018.
//

#include "Sound.h"

int Sound::loadSound() {

    //general
    if(!music.openFromFile("../RisorseMusic/LostWoods.ogg")){ return EXIT_FAILURE;}

    //shot
    if(!bufferShot.loadFromFile("../RisorseMusic/Heal.ogg")){ return EXIT_FAILURE; }
    soundShot.setBuffer(bufferShot);

    //Collision
    if(!bufferCollision.loadFromFile("../RisorseMusic/Collision.ogg")){ return EXIT_FAILURE; }
    soundCollision.setBuffer(bufferCollision);

    //Player Damage
    if(!bufferPDamage.loadFromFile("../RisorseMusic/Punch.ogg")){ return EXIT_FAILURE; }
    soundPDamage.setBuffer(bufferPDamage);

    //Coin
    if(!bufferCoin.loadFromFile("../RisorseMusic/Coin.ogg")){ return EXIT_FAILURE; }
    soundCoin.setBuffer(bufferCoin);

    //PowerUp&Nova
    if(!bufferPower.loadFromFile("../RisorseMusic/Item.ogg")){ return EXIT_FAILURE; }
    soundPower.setBuffer(bufferPower);

}