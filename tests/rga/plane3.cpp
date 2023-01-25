#include <doctest/doctest.h>
#include <maho/rga3/join3.h>
#include <maho/rga3/plane3.h>
#include <maho/rga3/projection3.h>

TEST_CASE("plane3")
{
    constexpr maho::rga::plane3<float> p1({1, 1, 1}, 0);
    CHECK_EQ(p1.normal(), maho::vec3<float>(1, 1, 1));
}

TEST_CASE("Construct by line and direction")
{
    constexpr auto a = maho::rga::point3<float>(0, 1, 1);
    constexpr auto b = maho::rga::point3<float>(10, 1, 1);
    constexpr auto l = join(a, b);
    constexpr auto o = project_to_origin(l).unitized();
    CHECK_EQ(o, maho::rga::point3<float>(0, 1, 1));
    constexpr auto d = maho::vec3<float>(0, 0, 1);
    constexpr auto p = maho::rga::plane3<float>::construct(l, d).unitized();
    CHECK_EQ(p.normal(), maho::vec3<float>(0, -1, 0));
    CHECK_EQ(p.weight(), 1);
}