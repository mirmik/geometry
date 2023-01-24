#ifndef MAHO_CGA_JOIN_H
#define MAHO_CGA_JOIN_H

#include <maho/cga/line3.h>
#include <maho/cga/plane3.h>
#include <maho/cga/point3.h>

namespace maho
{
    namespace cga
    {
        // Form a line as wedge product of two points.
        template <class T>
        constexpr line3<T> join(const cga::point3<T> &p,
                                const cga::point3<T> &q)
        {
            auto direction = p.w() * q.xyz() - q.w() * p.xyz();
            auto momentum = cross(p.xyz(), q.xyz());
            return {direction, momentum};
        }

        // Form a line as wedge product of two points.
        // p and q are unitized.
        template <class T>
        constexpr line3<T> join(const pnt3<T> &p, const pnt3<T> &q)
        {
            auto xyz = q.xyz() - p.xyz();
            auto w = cross(p.xyz(), q.xyz());
            return {xyz, w};
        }

        // Form a plane as wedge product of line and point.
        template <class T>
        constexpr plane3<T> join(const line3<T> &l, const point3<T> &p)
        {
            auto normal = cross(l.v(), p.xyz()) + l.m() * p.w();
            auto negoffset = -dot(l.m(), p.xyz());
            return {normal, negoffset};
        }

        // Form a plane as wedge product of three points.
        template <class T>
        constexpr plane3<T>
        join(const point3<T> &p, const point3<T> &q, const point3<T> &r)
        {
            return join(join(p, q), r);
        }
    }
}

#endif // MAHO_CGA_JOIN_H