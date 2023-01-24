#ifndef MAHO_BASE_PRODUCT_H
#define MAHO_BASE_PRODUCT_H

#include <maho/base/vec3.h>

namespace maho
{
    template <class A, class B>
    constexpr auto dot(const vec3<A> &p, const vec3<B> &v)
    {
        return p.x() * v.x() + p.y() * v.y() + p.z() * v.z();
    }

    template <class A, class B>
    constexpr auto cross(const vec3<A> &p, const vec3<B> &v)
    {
        return vec3<decltype(p.x() * v.x())>(p.y() * v.z() - p.z() * v.y(),
                                             p.z() * v.x() - p.x() * v.z(),
                                             p.x() * v.y() - p.y() * v.x());
    }
} // namespace maho

#endif