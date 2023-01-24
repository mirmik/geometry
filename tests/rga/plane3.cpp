#include <doctest/doctest.h>
#include <maho/rga/plane3.h>

TEST_CASE("plane3")
{
    constexpr maho::rga::plane3<float> p1({1, 1, 1}, 0);
    CHECK_EQ(p1.normal(), maho::vec3<float>(1, 1, 1));
}