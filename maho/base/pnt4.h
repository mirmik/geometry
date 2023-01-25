#ifndef MAHO_BASE_PNT4_H
#define MAHO_BASE_PNT4_H

#include <iostream>
#include <maho/base/vec4.h>

namespace maho
{
    template <typename T> class pnt4 : public vec4<T>
    {
    public:
        constexpr pnt4() : vec4<T>() {}
        constexpr pnt4(T x, T y, T z, T w) : vec4<T>(x, y, z, w) {}
        constexpr pnt4(const pnt4 &p) : vec4<T>(p) {}
        constexpr pnt4(const vec4<T> &v) : vec4<T>(v) {}
        constexpr pnt4 &operator=(const pnt4 &p)
        {
            vec4<T>::operator=(p);
            return *this;
        }
        constexpr pnt4 &operator=(const vec4<T> &v)
        {
            vec4<T>::operator=(v);
            return *this;
        }
    };
}

#endif // MAHO_BASE_PNT4_H