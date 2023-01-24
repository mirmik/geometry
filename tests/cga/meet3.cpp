#include <doctest/doctest.h>
#include <maho/cga/meet3.h>
#include <maho/rga/plane3.h>

TEST_CASE("Circle where sphere s and plane g intersect.")
{
    {
        constexpr auto s1 = maho::cga::sphere3<float>::construct({0, 0, 0}, 10);
        constexpr auto p1 = maho::rga::OXY<float>();
        constexpr auto c1 = maho::cga::meet(s1, p1);
        CHECK_EQ(c1.flat_center(), maho::rga::point3<float>(0, 0, 0, -1));
        CHECK_EQ(c1.radius(), 10);
    }
    {
        constexpr auto s1 = maho::cga::sphere3<float>::construct({3, 3, 2}, 10);
        constexpr auto p1 = maho::rga::plane3<float>({0, 0, 1}, -2);
        constexpr auto c1 = maho::cga::meet(s1, p1);
        CHECK_EQ(c1.flat_center().unitized(),
                 maho::rga::point3<float>(3, 3, 2, 1));
        CHECK_EQ(c1.radius(), 10);
    }
    {
        constexpr auto s1 = maho::cga::sphere3<float>::construct({3, 3, 1}, 10);
        constexpr auto p1 = maho::rga::plane3<float>({0, 0, 1}, -2);
        constexpr auto c1 = maho::cga::meet(s1, p1);
        CHECK_EQ(c1.flat_center().unitized(),
                 maho::rga::point3<float>(3, 3, 2, 1));
        CHECK_LT(c1.radius(), 10);
    }
    {
        constexpr auto s1 = maho::cga::sphere3<float>::construct({3, 3, 2}, 10);
        constexpr auto p1 = maho::rga::plane3<float>({0, 0, 1}, -1);
        constexpr auto c1 = maho::cga::meet(s1, p1);
        CHECK_EQ(c1.flat_center().unitized(),
                 maho::rga::point3<float>(3, 3, 1, 1));
        CHECK_LT(c1.radius(), 10);
    }

    // not intersected
    constexpr auto s1 = maho::cga::sphere3<float>::construct({0, 0, 0}, 10);
    constexpr auto p1 = maho::rga::plane3<float>({0, 0, 1}, -20);
    constexpr auto c1 = maho::cga::meet(s1, p1);
    CHECK_EQ(c1.flat_center().unitized(),
             maho::rga::point3<float>(0, 0, 20, 1));
    CHECK(std::isnan(c1.radius()));
}