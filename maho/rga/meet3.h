#ifndef MAHO_RGA_MEET3_H
#define MAHO_RGA_MEET3_H

// Based on https://rigidgeometricalgebra.org/wiki/index.php?title=Join_and_meet

#include <maho/base.h>
#include <maho/rga/line3.h>
#include <maho/rga/plane3.h>
#include <maho/rga/point3.h>

namespace maho
{
    namespace rga
    {
        // Line where planes g and h intersect.
        // Direction is zero if g and h are parallel.
        template <class T>
        constexpr line3<T> meet(const plane3<T> &g, const plane3<T> &h)
        {
            auto direction = cross(h.xyz(), g.xyz());
            auto momentum = h.w() * g.xyz() - g.w() * h.xyz();
            return {direction, momentum};
        }

        // Point where line l intersects plane g.
        // Weight w is zero if l is parallel to g.
        template <class T>
        constexpr point3<T> meet(const line3<T> &l, const plane3<T> &g)
        {
            auto xyz = cross(l.m(), g.xyz()) + l.v() * g.w();
            auto w = -dot(l.v(), g.xyz());
            return {xyz, w};
        }
    }
}

#endif