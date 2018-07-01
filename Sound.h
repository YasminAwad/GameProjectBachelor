//
// Created by Yasmin on 26/05/2018.
//

#ifndef GAME_PROVA3_SOUND_H
#define GAME_PROVA3_SOUND_H

#include <sfml/audio.hpp>

class Sound {
public:
    sf::Music music;

    sf::SoundBuffer bufferVictory;
    sf::Sound soundVictory;

    sf::SoundBuffer bufferGameOver;
    sf::Sound soundGameOver;

    sf::SoundBuffer bufferShot;
    sf::Sound soundShot;

    sf::SoundBuffer bufferCollision;
    sf::Sound soundCollision;

    sf::SoundBuffer bufferPDamage;
    sf::Sound soundPDamage;

    sf::SoundBuffer bufferCoin;
    sf::Sound soundCoin;

    sf::SoundBuffer bufferPower;
    sf::Sound soundPower;

    int loadSound();

};


#endif //GAME_PROVA3_SOUND_H
