#include <doctest/doctest.h>
#include <maho/cga/join3.h>
#include <maho/cga/meet3.h>
#include <maho/cga/perpendicular3.h>

TEST_CASE("Line perpendicular to plane g passing through point p.")
{
    constexpr maho::cga::plane3<float> p1({0, 0, 1}, -1);
    constexpr maho::cga::point3<float> p2(5, 0, 10, 1);
    constexpr auto l = maho::cga::perpendicular(p1, p2);
    CHECK_EQ(l.direction(), maho::vec3<float>(0, 0, -1));
    CHECK_EQ(l.momentum(), maho::vec3<float>(0, 5, 0));
    // meet line and plane
    constexpr auto p = maho::cga::meet(l, p1).unitized();
    CHECK_EQ(p, maho::cga::point3<float>(5, 0, 1, 1));
}

TEST_CASE("Plane perpendicular to line l containing point p.")
{
    constexpr auto OZ = maho::cga::OZ<double>();
    constexpr auto p = maho::cga::point3<double>(10, 0, 10, 1);
    constexpr auto pl = maho::cga::perpendicular(OZ, p);
    CHECK_EQ(pl.normal(), maho::vec3<double>(0, 0, -1));
    CHECK_EQ(pl.weight(), 10);
}

TEST_CASE("Plane perpendicular to plane g containing line l.")
{
    constexpr auto OZ = maho::cga::OZ<double>();
    constexpr auto l = maho::cga::join(maho::cga::point3<double>(0, 0, 0, 1),
                                       maho::cga::point3<double>(1, 0, 1, 1));
    constexpr auto OXY = maho::cga::OXY<double>();
    constexpr auto pl1 = maho::cga::perpendicular(OXY, OZ);
    CHECK_EQ(pl1.normal(), maho::vec3<double>(0, 0, 0));
    CHECK_EQ(pl1.weight(), 0);
    constexpr auto pl2 = maho::cga::perpendicular(OXY, l);
    CHECK_EQ(pl2.normal(), maho::vec3<double>(0, -1, 0));
    CHECK_EQ(pl2.weight(), 0);
}
