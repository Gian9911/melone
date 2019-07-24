#include "gtest/gtest.h"

#include "../Character.h"

TEST(Character, DefaultConstructor) {
    Character c;
    ASSERT_EQ(0, c.getPosX());
    ASSERT_EQ(0, c.getPosY());
    ASSERT_FALSE(c.isLegalFight( c));
    ASSERT_EQ(-2,c.receiveDamage(0));
}


TEST(Character, TestFightingMove) {
    Character c;
    ASSERT_TRUE(c.fight(c));
    c.move(1, 1);  // moving should disable fighting
    ASSERT_FALSE(c.fight(c));
}
