//
// Created by Yasmin on 29/05/2018.
//

#ifndef GAME_PROVA3_CUSTOMWALL_H
#define GAME_PROVA3_CUSTOMWALL_H


class CustomWall {
public:
    int wallSize=16; //33
    int roomStartX=0;
    int roomStartY=45;
    int rectSizeX=46;
    int rectSizeY=46;

    CustomWall(int wallSize, int roomStartX, int roomStartY);
    ~CustomWall(){}
};


#endif //GAME_PROVA3_CUSTOMWALL_H
