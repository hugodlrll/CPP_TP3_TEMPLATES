#include <gtest/gtest.h>
#include "../src/PointT.hpp"
#include "../src/Rectangle.hpp"
#include "../src/Carre.hpp"
#include "../src/ListeFormes.hpp"


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

// Tests pour la classe Rectangle
TEST(RectangleTest, DefaultConstructor) {
    Rectangle<int, int> r (10, 20);
    EXPECT_EQ(r.getL(), 10);
    EXPECT_EQ(r.getH(), 20);
}

TEST(RectangleTest, Surface)
{
    Rectangle<int, int> r (10, 20);
    EXPECT_EQ(r.surface(), 200);
}

TEST(RectangleTest, Perimetre)
{
    Rectangle<int, int> r (10, 20);
    EXPECT_EQ(r.perimetre(), 60);
}


// Tests pour la classe Carre
TEST(CarreTest, DefaultConstructor) {
    Carre<int, int> c(10);
    EXPECT_EQ(c.getL(), 10);
    EXPECT_EQ(c.getH(), 10);
}

TEST(CarreTest, Surface)
{
    Carre<int, int> c(10);
    EXPECT_EQ(c.surface(), 100);
}

TEST(CarreTest, Perimetre)
{
    Carre<int, int> c(10);
    EXPECT_EQ(c.perimetre(), 40);
}

// Tests pour la classe ListeFormes
TEST(ListeFormesTest, Ajouter) {
    ListeFormes<int, int> lf;
    Carre<int, int> c(10);
    lf.ajouter(&c);
    EXPECT_EQ(lf.getSize(), 1);
}

TEST(ListeFormesTest, Supprimer) {
    ListeFormes<int, int> lf;
    Carre<int, int> c(10);
    lf.ajouter(&c);
    lf.supprimer(&c);
    EXPECT_EQ(lf.getSize(), 0);
}

TEST(ListeFormesTest, CalcSurfaceTot) {
    ListeFormes<int, int> lf;
    Carre<int, int> c(10);
    Rectangle<int, int> r (10, 20);
    lf.ajouter(&c);
    lf.ajouter(&r);
    int surf = lf.calcSurfaceTot();
    EXPECT_EQ(surf, 300);    
}

TEST(ListeFormesTest, CalcBoiteEnglobante) {
    ListeFormes<int, int> lf;
    Carre<int, int> c(10);
    Rectangle<int, int> r (10, 20);
    tuple<int, int> t (10, 20);
    lf.ajouter(&c);
    lf.ajouter(&r);
    tuple<int,int> be = lf.calcBoiteEnglobante();

    EXPECT_EQ(std::get<0>(be), std::get<0>(t));
    EXPECT_EQ(std::get<1>(be), std::get<1>(t));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}