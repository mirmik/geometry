#include <doctest/doctest.h>
#include <maho/base.h>

TEST_CASE("vec3")
{
    maho::vec3<float> v1(1, 2, 3);
    maho::vec3<float> v2(4, 5, 6);
    maho::vec3<float> v3 = v1 + v2;
    CHECK_EQ(v3, maho::vec3<float>(5, 7, 9));
}