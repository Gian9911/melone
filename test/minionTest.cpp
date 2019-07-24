//
// Created by gianluca on 21/07/19.
//

#include "gtest/gtest.h"

#include "../minion.h"



TEST(minion, TestFightingMove) {
    minion c;
    ASSERT_TRUE(c.fight());
    c.randomMove();
    ASSERT_FALSE(c.fight());
}
