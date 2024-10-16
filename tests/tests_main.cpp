#include <gtest/gtest.h>
#include "../src/PointT.hpp"



TEST(PointTTest, DefaultConstructor) {
    PointT<int> p;
    EXPECT_EQ(p.getX(), 0);
    EXPECT_EQ(p.getY(), 0);
}

TEST(PointTTest, ParameterizedConstructor) {
    PointT<int> p(3, 4);
    EXPECT_EQ(p.getX(), 3);
    EXPECT_EQ(p.getY(), 4);
}

TEST(PointTTest, SetX) {
    PointT<int> p;
    p.setX(5);
    EXPECT_EQ(p.getX(), 5);
}

TEST(PointTTest, SetY) {
    PointT<int> p(0,0);
    p.setY(6);
    EXPECT_EQ(p.getY(), 6);
}

TEST(PointTTest, translater) {
    PointT<int> p(0,0);
    p.translater(6,4);
    EXPECT_EQ(p.getX(), 6);
    EXPECT_EQ(p.getY(), 4);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}