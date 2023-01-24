#ifndef MAHO_CGA_JOIN3_H
#define MAHO_CGA_JOIN3_H

// Based on https://rigidgeometricalgebra.org/wiki/index.php?title=Join_and_meet

#include <maho/cga/line3.h>
#include <maho/cga/plane3.h>
#include <maho/cga/point3.h>

namespace maho
{
    namespace cga
    {
        // Line containing points p and q.
        // Zero if p and q are coincident.
        template <class T>
        constexpr line3<T> join(const cga::point3<T> &p,
                                const cga::point3<T> &q)
        {
            auto direction = p.w() * q.xyz() - q.w() * p.xyz();
            auto momentum = cross(p.xyz(), q.xyz());
            return {direction, momentum};
        }

        // Line containing points p and q.
        // Zero if p and q are coincident.
        // p and q are unitized.
        template <class T>
        constexpr line3<T> join(const pnt3<T> &p, const pnt3<T> &q)
        {
            auto xyz = q.xyz() - p.xyz();
            auto w = cross(p.xyz(), q.xyz());
            return {xyz, w};
        }

        // Plane containing line l and point p.
        // Zero if p lies on the line l.
        template <class T>
        constexpr plane3<T> join(const line3<T> &l, const point3<T> &p)
        {
            auto normal = cross(l.v(), p.xyz()) + l.m() * p.w();
            auto negoffset = -dot(l.m(), p.xyz());
            return {normal, negoffset};
        }

        // Form a plane as wedge product of three points.
        // Zero if two or more points are coincident.
        template <class T>
        constexpr plane3<T>
        join(const point3<T> &p, const point3<T> &q, const point3<T> &r)
        {
            return join(join(p, q), r);
        }
    }
}

#endif // MAHO_CGA_JOIN_H