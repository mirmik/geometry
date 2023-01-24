#include <doctest/doctest.h>
#include <maho/cga/meet3.h>

TEST_CASE("line when meets two planes")
{
    constexpr maho::cga::plane3<float> p1({1, 0, 0}, -1);
    constexpr maho::cga::plane3<float> p2({0, 1, 0}, -1);
    constexpr auto l = maho::cga::meet(p1, p2);
    CHECK_EQ(l.direction(), maho::vec3<float>(0, 0, -1));
    CHECK_EQ(l.momentum(), maho::vec3<float>(-1, 1, 0));
}

TEST_CASE("point when line meet plane")
{
    constexpr maho::cga::plane3<float> p1({1, 0, 0}, -1);
    constexpr maho::cga::line3<float> l1({1, 0, 0}, {0, 0, 0});
    constexpr auto p = maho::cga::meet(l1, p1).unitized();
    CHECK_EQ(p, maho::cga::point3<float>(1, 0, 0, 1));
}