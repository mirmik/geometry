#ifndef MAHO_BASE_PNT3_H
#define MAHO_BASE_PNT3_H

#include <iostream>
#include <maho/base/vec3.h>

namespace maho
{
    template <typename T> class pnt3 : public vec3<T>
    {
    public:
        constexpr pnt3() : vec3<T>() {}
        constexpr pnt3(T x, T y, T z) : vec3<T>(x, y, z) {}
        constexpr pnt3(const pnt3 &p) : vec3<T>(p) {}
        constexpr pnt3(const vec3<T> &v) : vec3<T>(v) {}
        constexpr pnt3 &operator=(const pnt3 &p)
        {
            vec3<T>::operator=(p);
            return *this;
        }
        constexpr pnt3 &operator=(const vec3<T> &v)
        {
            vec3<T>::operator=(v);
            return *this;
        }
    };
}

#endif // MAHO_BASE_PNT3_H