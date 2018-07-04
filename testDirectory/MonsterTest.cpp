//
// Created by Yasmin on 30/06/2018.
//

#include "gtest/gtest.h"
#include "../Monster.h"

TEST(Monster, Monster_Test) {
    Monster monster(0,0, 5, 30, Monsters::bat);

    ASSERT_EQ(monster.rect.getPosition().x, 0);
    ASSERT_EQ(monster.rect.getPosition().y, 0);
    ASSERT_EQ(monster.getDamage(), 5);
    ASSERT_EQ(monster.getHP(), 30);
    ASSERT_EQ(monster.monsterClass, Monsters::bat);

}

TEST(Monster, Monster_Setting_Test) {
    Monster monster(0, 0, 5, 30, Monsters::bat);

    monster.rect.setPosition(5,5);
    monster.updatePosition();

    ASSERT_EQ(monster.rect.getPosition().x, 5);
    ASSERT_EQ(monster.rect.getPosition().y, 5);
    ASSERT_TRUE(monster.canMoveUp);
    ASSERT_TRUE(monster.canMoveDown);
    ASSERT_TRUE(monster.canMoveRight);
    ASSERT_TRUE(monster.canMoveLeft);

    monster.setDirection(Direction::up);
    monster.monsterWall();
    ASSERT_FALSE(monster.canMoveUp);

    ASSERT_FALSE(monster.getAggroed());
    monster.setAggroed(true);
    ASSERT_TRUE(monster.getAggroed());

}
