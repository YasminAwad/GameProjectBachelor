//
// Created by Yasmin on 13/06/2018.
//

#include "gtest/gtest.h"
#include "../Map.h"

TEST(Map, Map_Setting_Test) {
    Map map(10, 30, TileEnum::grass);
    map.setTile(9, 20, false);

    ASSERT_EQ(map.getHeight(), 30);
    ASSERT_EQ(map.getWidth(), 10);
    ASSERT_FALSE(map.getTile(9, 20)->isWalkable());

}