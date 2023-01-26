#ifndef MAHO_RGA3_DISTANCE_H
#define MAHO_RGA3_DISTANCE_H

#include <maho/base.h>
#include <maho/ga0/magnitude.h>
#include <maho/rga3/line3.h>
#include <maho/rga3/plane3.h>
#include <maho/rga3/point3.h>

namespace maho
{
    namespace rga
    {
        // Distance between points p and q.
        template <typename T>
        constexpr ga0::magnitude<T> distance(const point3<T> &p,
                                             const point3<T> &q)
        {
            auto a = p.w() * q.xyz() - q.w() * p.xyz();
            auto b = p.w() * q.w();
            return ga0::magnitude<T>(length(a), b);
        }

        // Perpendicular distance between point p and line l.
        template <typename T>
        constexpr ga0::magnitude<T> distance(const point3<T> &p,
                                             const line3<T> &l)
        {
            auto a = cross(l.v(), p.xyz()) + l.m() * p.w();
            auto b = p.w() * length(l.v());
            return ga0::magnitude<T>(length(a), b);
        }

        // Perpendicular distance between point p and plane g.
        template <typename T>
        constexpr ga0::magnitude<T> distance(const point3<T> &p,
                                             const plane3<T> &g)
        {
            auto a = std::abs(dot(p.xyz(), g.xyz()) + p.w() * g.w());
            auto b = p.w() * length(g.xyz());
            return ga0::magnitude<T>(a, b);
        }

        // Perpendicular distance d between lines k and l.
        template <typename T>
        constexpr ga0::magnitude<T> distance(const line3<T> &k,
                                             const line3<T> &l)
        {
            auto a = std::abs(dot(l.v(), k.m()) + dot(l.m(), k.v()));
            auto b = length(cross(l.v(), k.v()));
            return ga0::magnitude<T>(a, b);
        }
    }
}

#endif