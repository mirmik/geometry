#ifndef MAHO_BASE_VECPNT4_H
#define MAHO_BASE_VECPNT4_H

#include <maho/base/pnt4.h>
#include <maho/base/vec4.h>

namespace maho
{
    template <class T>
    constexpr vec4<T> operator-(const pnt4<T> &p1, const pnt4<T> &p2)
    {
        return vec4<T>(
            p1.x() - p2.x(), p1.y() - p2.y(), p1.z() - p2.z(), p1.w() - p2.w());
    }

    template <class T>
    constexpr pnt4<T> operator+(const pnt4<T> &p, const vec4<T> &v)
    {
        return pnt4<T>(p.x() + v.x(), p.y() + v.y(), p.z() + v.z() + v.w());
    }

    template <class T>
    constexpr pnt4<T> operator-(const pnt4<T> &p, const vec4<T> &v)
    {
        return pnt4<T>(p.x() - v.x(), p.y() - v.y(), p.z() - v.z());
    }

    template <class T>
    constexpr vec4<T> operator-(const vec4<T> &p1, const vec4<T> &p2)
    {
        return vec4<T>(
            p1.x() - p2.x(), p1.y() - p2.y(), p1.z() - p2.z(), p1.w() - p2.w());
    }

    template <class T>
    constexpr vec4<T> operator+(const vec4<T> &p, const vec4<T> &v)
    {
        return vec4<T>(p.x() + v.x(), p.y() + v.y(), p.z() + v.z()),
               p.w() + v.w();
    }

    template <class A, class B> constexpr auto operator*(const vec4<A> &p, B v)
    {
        return vec4<decltype(p.x() * v)>(
            p.x() * v, p.y() * v, p.z() * v, p.w() * v);
    }

    template <class A, class B> constexpr auto operator*(A v, const vec4<B> &p)
    {
        return vec4<decltype(p.x() * v)>(
            p.x() * v, p.y() * v, p.z() * v, p.w() * v);
    }

    template <class A, class B> constexpr auto operator/(const vec4<A> &p, B v)
    {
        return vec4<decltype(p.x() / v)>(
            p.x() / v, p.y() / v, p.z() / v, p.w() / v);
    }

    template <class A, class B> constexpr auto operator/(A v, const vec4<B> &p)
    {
        return vec4<decltype(p.x() / v)>(
            p.x() / v, p.y() / v, p.z() / v, p.w() / v);
    }

    template <class A> constexpr auto operator-(const vec4<A> &p)
    {
        return vec4<decltype(-p.x())>(-p.x(), -p.y(), -p.z(), -p.w());
    }
}

#endif // MAHO_BASE_VECPNT4_H