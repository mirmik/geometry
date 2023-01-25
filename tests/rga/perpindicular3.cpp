#include <doctest/doctest.h>
#include <maho/rga3/join3.h>
#include <maho/rga3/meet3.h>
#include <maho/rga3/perpendicular3.h>

TEST_CASE("Line perpendicular to plane g passing through point p.")
{
    constexpr maho::rga::plane3<float> p1({0, 0, 1}, -1);
    constexpr maho::rga::point3<float> p2(5, 0, 10, 1);
    constexpr auto l = maho::rga::perpendicular(p1, p2);
    CHECK_EQ(l.direction(), maho::vec3<float>(0, 0, -1));
    CHECK_EQ(l.momentum(), maho::vec3<float>(0, 5, 0));
    // meet line and plane
    constexpr auto p = maho::rga::meet(l, p1).unitized();
    CHECK_EQ(p, maho::rga::point3<float>(5, 0, 1, 1));
}

TEST_CASE("Plane perpendicular to line l containing point p.")
{
    constexpr auto OZ = maho::rga::OZ<double>();
    constexpr auto p = maho::rga::point3<double>(10, 0, 10, 1);
    constexpr auto pl = maho::rga::perpendicular(OZ, p);
    CHECK_EQ(pl.normal(), maho::vec3<double>(0, 0, -1));
    CHECK_EQ(pl.weight(), 10);
}

TEST_CASE("Plane perpendicular to plane g containing line l.")
{
    constexpr auto OZ = maho::rga::OZ<double>();
    constexpr auto l = maho::rga::join(maho::rga::point3<double>(0, 0, 0, 1),
                                       maho::rga::point3<double>(1, 0, 1, 1));
    constexpr auto OXY = maho::rga::OXY<double>();
    constexpr auto pl1 = maho::rga::perpendicular(OXY, OZ);
    CHECK_EQ(pl1.normal(), maho::vec3<double>(0, 0, 0));
    CHECK_EQ(pl1.weight(), 0);
    constexpr auto pl2 = maho::rga::perpendicular(OXY, l);
    CHECK_EQ(pl2.normal(), maho::vec3<double>(0, -1, 0));
    CHECK_EQ(pl2.weight(), 0);
}
