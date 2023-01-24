#include <doctest/doctest.h>
#include <maho/cga/plane3.h>

TEST_CASE("plane3")
{
    constexpr maho::cga::plane3<float> p1({1, 1, 1}, 0);
    CHECK_EQ(p1.normal(), maho::vec3<float>(1, 1, 1));
}