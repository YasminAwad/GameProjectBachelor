//
// Created by Yasmin on 14/05/2018.
//

#include "Random.h"

int Random::generateRandom(int max) {
    int randomNumber=rand();
    float random=(randomNumber%max)+1;
    int myRandom=random;

    return myRandom;
}

int Random::generateRandom0(int max) {
    int randomNumber=rand();
    float random=(randomNumber%max);
    int myRandom=random;

    return myRandom;
}

bool Random::generateRandomBool() {
    int randomNumber=rand();
    float myRandom=(randomNumber%2)+1;
    if(myRandom==1)
        return true;
    else
        return false;
}