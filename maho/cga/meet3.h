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
        template <class T>
        constexpr line3<T> meet(const plane3<T> &g, const plane3<T> &h)
        {
            auto direction = cross(h.xyz(), g.xyz());
            auto momentum = h.w() * g.xyz() - g.w() * h.xyz();
            return {direction, momentum};
        }
    }
}

#endif