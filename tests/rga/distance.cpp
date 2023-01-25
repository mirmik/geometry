#include <doctest/doctest.h>
#include <maho/rga3/distance3.h>
#include <maho/rga3/join3.h>

TEST_CASE("Distance between two points.")
{
    constexpr auto a = maho::rga::point3<float>(0, 0, 1);
    constexpr auto b = maho::rga::point3<float>(10, 0, 1);
    constexpr auto d = maho::rga::distance(a, b);
    CHECK_EQ(d, maho::ga0::magnitude<float>(10, 1));
}

TEST_CASE("Distance between point and line.")
{
    constexpr auto a = maho::rga::point3<float>(-10, 0, 1);
    constexpr auto b = maho::rga::point3<float>(10, 0, 1);
    constexpr auto c = maho::rga::point3<float>(0, 1, 1);
    constexpr auto l = maho::rga::join(a, b);
    constexpr auto d = maho::rga::distance(c, l).unitized();
    CHECK_EQ(d, maho::ga0::magnitude<float>(1, 1));
}

TEST_CASE("Distance between point and plane.")
{
    constexpr auto a = maho::rga::point3<float>(0, 0, 1);
    constexpr auto b = maho::rga::point3<float>(10, 0, 1);
    constexpr auto c = maho::rga::point3<float>(0, 10, 1);
    constexpr auto x = maho::rga::point3<float>(0, 1, 2);
    constexpr auto p = maho::rga::join(a, b, c);
    constexpr auto d = maho::rga::distance(x, p).unitized();
    CHECK_EQ(d, maho::ga0::magnitude<float>(1, 1));
}

TEST_CASE("Distance between lines")
{
    constexpr auto a = maho::rga::point3<float>(-10, 0, 1);
    constexpr auto b = maho::rga::point3<float>(10, 0, 1);
    constexpr auto c = maho::rga::point3<float>(0, -10, 2);
    constexpr auto d = maho::rga::point3<float>(0, 10, 2);
    constexpr auto l1 = maho::rga::join(a, b);
    constexpr auto l2 = maho::rga::join(c, d);
    constexpr auto d1 = maho::rga::distance(l1, l2).unitized();
    CHECK_EQ(d1, maho::ga0::magnitude<float>(1, 1));
}
