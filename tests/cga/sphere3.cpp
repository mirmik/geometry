#include <doctest/doctest.h>
#include <maho/cga/sphere3.h>

TEST_CASE("sphere")
{
    auto s1 = maho::cga::sphere3<float>::construct({3, 2, 3}, 3);
    CHECK_EQ(s1.center(), maho::vec3<float>(3, 2, 3));
    CHECK_EQ(s1.radius(), 3);
}