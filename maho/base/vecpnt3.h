#ifndef MAHO_BASE_VECPNT3_H
#define MAHO_BASE_VECPNT3_H

#include <maho/base/pnt3.h>
#include <maho/base/vec3.h>

namespace maho
{
    template <class T>
    constexpr vec3<T> operator-(const pnt3<T> &p1, const pnt3<T> &p2)
    {
        return vec3<T>(p1.x() - p2.x(), p1.y() - p2.y(), p1.z() - p2.z());
    }

    template <class T>
    constexpr pnt3<T> operator+(const pnt3<T> &p, const vec3<T> &v)
    {
        return pnt3<T>(p.x() + v.x(), p.y() + v.y(), p.z() + v.z());
    }

    template <class T>
    constexpr pnt3<T> operator-(const pnt3<T> &p, const vec3<T> &v)
    {
        return pnt3<T>(p.x() - v.x(), p.y() - v.y(), p.z() - v.z());
    }

    template <class T>
    constexpr vec3<T> operator-(const vec3<T> &p1, const vec3<T> &p2)
    {
        return vec3<T>(p1.x() - p2.x(), p1.y() - p2.y(), p1.z() - p2.z());
    }

    template <class T>
    constexpr vec3<T> operator+(const vec3<T> &p, const vec3<T> &v)
    {
        return vec3<T>(p.x() + v.x(), p.y() + v.y(), p.z() + v.z());
    }

    template <class A, class B> constexpr auto operator*(const vec3<A> &p, B v)
    {
        return vec3<decltype(p.x() * v)>(p.x() * v, p.y() * v, p.z() * v);
    }

    template <class A, class B> constexpr auto operator*(A v, const vec3<B> &p)
    {
        return vec3<decltype(p.x() * v)>(p.x() * v, p.y() * v, p.z() * v);
    }

    template <class A, class B> constexpr auto operator/(const vec3<A> &p, B v)
    {
        return vec3<decltype(p.x() / v)>(p.x() / v, p.y() / v, p.z() / v);
    }

    template <class A, class B> constexpr auto operator/(A v, const vec3<B> &p)
    {
        return vec3<decltype(p.x() / v)>(p.x() / v, p.y() / v, p.z() / v);
    }
}

#endif // MAHO_BASE_VECPNT3_H