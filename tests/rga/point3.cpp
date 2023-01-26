#include <doctest/doctest.h>
#include <maho/rga3/point3.h>

TEST_CASE("point3")
{
    constexpr maho::rga::point3<float> p1(1, 2, 3);
    constexpr maho::rga::point3<float> p2(maho::vec3<float>(4, 5, 6), 0);
    CHECK_EQ(p1, p1);
    CHECK_NE(p1, p2);
    CHECK_EQ(p1, maho::rga::point3<float>(1, 2, 3, 1));
    CHECK_EQ(p2, maho::rga::point3<float>(4, 5, 6, 0));
    CHECK(p2.is_infinite());
}