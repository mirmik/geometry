#ifndef MAHO_CGA_MEET3_H
#define MAHO_CGA_MEET3_H

#include <maho/base.h>
#include <maho/cga/line3.h>
#include <maho/cga/plane3.h>
#include <maho/cga/point3.h>

namespace maho
{
    namespace cga
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