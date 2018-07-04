//
// Created by Yasmin on 04/07/2018.
//
#include "gtest/gtest.h"
#include "../Projectile.h"

TEST(Projectile, Projectile_Setting_Test) {

    Projectile p;

    p.setAttackDamage(15);
    ASSERT_EQ(p.getAttackDamage(), 15);

    p.setDirection(Direction::up);
    ASSERT_EQ(p.getDirection(), Direction::up);
}


