#ifndef MAHO_RGA_JOIN3_H
#define MAHO_RGA_JOIN3_H

// Based on https://rigidgeometricalgebra.org/wiki/index.php?title=Join_and_meet

#include <maho/rga/line3.h>
#include <maho/rga/plane3.h>
#include <maho/rga/point3.h>

namespace maho
{
    namespace rga
    {
        // Line containing points p and q.
        // Zero if p and q are coincident.
        template <class T>
        constexpr line3<T> join(const rga::point3<T> &p,
                                const rga::point3<T> &q)
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

        // Plane containing points p, q, r.
        // Zero if two or more points are coincident.
        template <class T>
        constexpr plane3<T>
        join(const point3<T> &p, const point3<T> &q, const point3<T> &r)
        {
            return join(join(p, q), r);
        }
    }
}

#endif // MAHO_RGA_JOIN_H