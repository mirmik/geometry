#include <doctest/doctest.h>
#include <maho/rga3/join3.h>
#include <maho/rga3/projection3.h>

TEST_CASE("Point closest to the origin on the line l.")
{
    {
        constexpr maho::rga::point3<float> a(0, 1, 0);
        constexpr maho::rga::point3<float> b(1, 1, 0);
        constexpr auto l = maho::rga::join(a, b);
        constexpr auto p = maho::rga::project_to_origin(l);
        CHECK_EQ(p.xyz(), maho::vec3<float>{0, 1, 0});
        CHECK_EQ(p.w(), 1);
    }
    {
        constexpr maho::rga::point3<float> a(1, 5, 50);
        constexpr maho::rga::point3<float> b(5, 1, 50);
        constexpr auto l = maho::rga::join(a, b);
        constexpr auto p = maho::rga::project_to_origin(l).unitized();
        CHECK_EQ(p.xyz(), maho::vec3<float>{3, 3, 50});
        CHECK_EQ(p.w(), 1);
    }
}