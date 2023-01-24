#include <doctest/doctest.h>
#include <maho/cga/line3.h>

TEST_CASE("line3")
{
    constexpr maho::cga::line3<float> l1({1, 2, 3}, {4, 5, 6});
    CHECK_EQ(l1.direction(), maho::vec3<float>(1, 2, 3));
    CHECK_EQ(l1.momentum(), maho::vec3<float>(4, 5, 6));
}