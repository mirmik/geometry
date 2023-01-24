#include <doctest/doctest.h>
#include <maho/rga/meet3.h>

TEST_CASE("Line where planes g and h intersect.")
{
    constexpr maho::rga::plane3<float> p1({1, 0, 0}, -1);
    constexpr maho::rga::plane3<float> p2({0, 1, 0}, -1);
    constexpr auto l = maho::rga::meet(p1, p2);
    CHECK_EQ(l.direction(), maho::vec3<float>(0, 0, -1));
    CHECK_EQ(l.momentum(), maho::vec3<float>(-1, 1, 0));
}

TEST_CASE("Point where line l intersects plane g.")
{
    constexpr maho::rga::plane3<float> p1({1, 0, 0}, -1);
    constexpr maho::rga::line3<float> l1({1, 0, 0}, {0, 0, 0});
    constexpr auto p = maho::rga::meet(l1, p1).unitized();
    CHECK_EQ(p, maho::rga::point3<float>(1, 0, 0, 1));
}