#include <doctest/doctest.h>
#include <maho/cga/join3.h>

TEST_CASE("join points to line")
{
    constexpr auto a = maho::cga::point3<float>(0, 0, 1);
    constexpr auto b = maho::cga::point3<float>(10, 0, 1);
    constexpr auto l = join(a, b);
    CHECK_EQ(l.direction(), maho::vec3<float>(10, 0, 0));
    CHECK_EQ(l.momentum(), maho::vec3<float>(0, 10, 0));
    constexpr auto ul = l.unitized();
    CHECK_EQ(ul.direction(), maho::vec3<float>(1, 0, 0));
    CHECK_EQ(ul.momentum(), maho::vec3<float>(0, 1, 0));
}

TEST_CASE("join points to plane")
{
    constexpr auto a = maho::cga::point3<double>(0, 0, 1);
    constexpr auto b = maho::cga::point3<double>(10, 0, 1);
    constexpr auto c = maho::cga::point3<double>(0, 10, 1);
    constexpr maho::cga::plane3<double> p = join(a, b, c);
    CHECK_EQ(p.normal(), maho::vec3<double>(0, 0, 100));
    CHECK_EQ(p.weight(), -100);
    constexpr auto up = p.unitized();
    CHECK_EQ(up.normal(), maho::vec3<double>(0, 0, 1));
    CHECK_EQ(up.weight(), -1);
}