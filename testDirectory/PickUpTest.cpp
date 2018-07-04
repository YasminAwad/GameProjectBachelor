//
// Created by Yasmin on 01/07/2018.
//
#include "gtest/gtest.h"
#include "../PickUp.h"
#include "../Monster.h"


TEST(PickUp, PickUP_Setting_Test) {
    PickUp pickUp;
    Monster monster1 (0,0, 5, 35, Monsters::bat);
    std::vector<Monster> monsterArray;
    monsterArray.push_back(monster1);

    ASSERT_FALSE(pickUp.isCoin);
    ASSERT_FALSE(pickUp.isFood);
    ASSERT_FALSE(pickUp.isPowerUp);
    ASSERT_FALSE(pickUp.isNovaAttack);

    pickUp.dropCoin(monsterArray, 0);
    ASSERT_TRUE(pickUp.isCoin);
    ASSERT_FALSE(pickUp.isFood);
    ASSERT_FALSE(pickUp.isPowerUp);
    ASSERT_FALSE(pickUp.isNovaAttack);

    pickUp.dropFood(monsterArray, 0);
    ASSERT_TRUE(pickUp.isFood);
    ASSERT_FALSE(pickUp.isCoin);
    ASSERT_FALSE(pickUp.isPowerUp);
    ASSERT_FALSE(pickUp.isNovaAttack);

    pickUp.dropPowerUp(monsterArray, 0);
    ASSERT_TRUE(pickUp.isPowerUp);
    ASSERT_FALSE(pickUp.isCoin);
    ASSERT_FALSE(pickUp.isFood);
    ASSERT_FALSE(pickUp.isNovaAttack);

    pickUp.dropNovaAttack(monsterArray, 0);
    ASSERT_TRUE(pickUp.isNovaAttack);
    ASSERT_FALSE(pickUp.isCoin);
    ASSERT_FALSE(pickUp.isFood);
    ASSERT_FALSE(pickUp.isPowerUp);

    ASSERT_EQ(pickUp.rect.getPosition().x,monsterArray[0].rect.getPosition().x);
    ASSERT_EQ(pickUp.rect.getPosition().y,monsterArray[0].rect.getPosition().y);

}