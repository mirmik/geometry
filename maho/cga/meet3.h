#ifndef MAHO_CGA_MEET3_H
#define MAHO_CGA_MEET3_H

#include <maho/cga/circle3.h>
#include <maho/cga/sphere3.h>
#include <maho/rga/line3.h>
#include <maho/rga/plane3.h>
#include <maho/rga/point3.h>

namespace maho
{
    namespace cga
    {
        // Circle where sphere s and plane g intersect.
        // If circle radius is nan then s and g are not intersecting.
        template <class T>
        constexpr circle3<T> meet(const sphere3<T> &s, const rga::plane3<T> &g)
        {
            auto _g = s.u() * g.xyz();
            auto w = s.u() * g.w();
            auto v = cross(g.xyz(), s.xyz());
            auto m = s.xyz() * g.w() - g.xyz() * s.w();
            return circle3<T>(_g, w, v, m);
        }
    }
}

#endif