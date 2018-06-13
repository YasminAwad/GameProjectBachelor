//
// Created by Yasmin on 13/06/2018.
//
#include "gtest/gtest.h"
#include "../GameCharacter.h"

TEST(GameCharacter, GameCharacter_Test) {
    GameCharacter character(0, 0, 5, 50, 50, GCharacters::boy);
;
    ASSERT_EQ(character.rect.getPosition().x, 0);
    ASSERT_EQ(character.rect.getPosition().y, 0);
}

