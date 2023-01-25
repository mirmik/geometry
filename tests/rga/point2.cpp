#include <doctest/doctest.h>
#include <maho/rga2/point2.h>

TEST_CASE("point2")
{
    constexpr maho::rga::point2<float> p1(1, 2);
    CHECK_EQ(p1.x(), 1);
    CHECK_EQ(p1.y(), 2);
}