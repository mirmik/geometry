#ifndef MAHO_CGA_PERPENDICULAR3_H
#define MAHO_CGA_PERPENDICULAR3_H

#include <maho/cga/line3.h>
#include <maho/cga/plane3.h>
#include <maho/cga/point3.h>

namespace maho
{
    namespace cga
    {
        // Line perpendicular to plane g passing through point p.
        template <class T>
        constexpr line3<T> perpendicular(const plane3<T> &g, const point3<T> &p)
        {
            auto direction = -(g.xyz() * p.w());
            auto momentum = cross(g.xyz(), p.xyz());
            return {direction, momentum};
        }

        // Plane perpendicular to line l containing point p.
        template <class T>
        constexpr plane3<T> perpendicular(const line3<T> &l, const point3<T> &p)
        {
            auto normal = -l.v() * p.w();
            auto negoffset = dot(l.v(), p.xyz());
            return {normal, negoffset};
        }

        // Plane perpendicular to plane g containing line l.
        // Normal direction is (0,0,0) if l is perpendicular to g.
        template <class T>
        constexpr plane3<T> perpendicular(const plane3<T> &g, const line3<T> &l)
        {
            auto normal = cross(l.v(), g.xyz());
            auto negoffset = -dot(l.m(), g.xyz());
            return {normal, negoffset};
        }
    }
}

#endif // MAHO_CGA_PERPENDICULAR3_H