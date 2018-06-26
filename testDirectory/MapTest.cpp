//
// Created by Yasmin on 13/06/2018.
//

#include "gtest/gtest.h"
#include "../Map.h"

TEST(Map, Map_Setting_Test) {
    Map map(10, 30, TileEnum::grass);

    ASSERT_EQ(map.getHeight(), 30);
    ASSERT_EQ(map.getWidth(), 10);
}

