#ifndef MAHO_RGA3_PROJECTION3_H
#define MAHO_RGA3_PROJECTION3_H

#include <maho/rga3/line3.h>
#include <maho/rga3/plane3.h>
#include <maho/rga3/point3.h>

namespace maho
{
    namespace rga
    {
        // Point closest to the origin on the plane g.
        template <class T>
        constexpr point3<T> project_to_origin(const plane3<T> &g)
        {
            return {-g.xyz() * g.w(), g.xyz().norm2()};
        }

        // Point closest to the origin on the line l.
        template <class T>
        constexpr point3<T> project_to_origin(const line3<T> &l)
        {
            return {cross(l.v(), l.m()), l.v().norm2()};
        }

    }
}

#endif
