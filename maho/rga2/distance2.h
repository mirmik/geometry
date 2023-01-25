#ifndef MAHO_RGA2_DISTANCE2_H
#define MAHO_RGA2_DISTANCE2_H

#include <maho/ga0/magnitude.h>
#include <maho/rga2/point2.h>

namespace maho
{
    namespace rga2
    {
        // Distance d between points p and q.
        template <typename T>
        constexpr ga0::magnitude<T> distance(const point2<T> &p,
                                             const point2<T> &q)
        {
            auto a = p.w() * q.xy() - q.w() * p.xy();
            auto b = p.w() * q.w();
            return ga0::magnitude<T>(a.norm(), b);
        }

        // TODO: Perpendicular distance d between point p and line l.
    }
}