//
// Created by Yasmin on 13/06/2018.
//
#include "gtest/gtest.h"
#include "../GameCharacter.h"

TEST(GameCharacter, GameCharacter_Test) {
    GameCharacter character(0, 0, 5, 50, 50, GCharacters::boy);

    ASSERT_EQ(character.rect.getPosition().x, 0);
    ASSERT_EQ(character.rect.getPosition().y, 0);
    ASSERT_EQ(character.damage, 5);
    ASSERT_EQ(character.hp, 50);
    ASSERT_EQ(character.maxHP, 50);
    ASSERT_EQ(character.gameCharacter, GCharacters::boy);
}

TEST(GameCharacter,GameCharacter_Setting_Test) {
    GameCharacter *character = new GameCharacter(0, 0, 10, 20, 20, GCharacters::boy);

    character->setmaxHP(200);
    character->setHP(200);
    character->setDamage(35);

    ASSERT_EQ(200, character->getHP());
    ASSERT_EQ(35, character->getDamage());

}

TEST(GameCharacter,GameCharacter_move_Test) {
    GameCharacter *character = new GameCharacter (0,0,10,20,20,GCharacters::boy);
    character->rect.move(1, 4);
    character->update();

    ASSERT_EQ(1, character->rect.getPosition().x);
    ASSERT_EQ(4, character->rect.getPosition().y);
}

TEST(GameCharacter, GameCharacter_heal_test){
    GameCharacter* character= new GameCharacter(0,0,10,20,100,GCharacters::boy);
    character->setHP(60);
    character->heal(30);
    ASSERT_EQ(90,character->getHP());
    ASSERT_EQ(100,character->getmaxHP());
    delete character;
}
