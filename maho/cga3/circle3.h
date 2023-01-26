#ifndef MAHO_CGA_CIRCLE3_H
#define MAHO_CGA_CIRCLE3_H

/// @file maho/cga3/circle3.h

/// @class maho::rga::circle3
/// @brief 3D space circle in CGA representation.
///
/// CGA (trivector) : c = gx*e423 + gy*e431 + gz*e412 + gw*e321 + vx*e415 +
/// vy*e425 + vz*e435 + mx*e235 + my*e315 + mz*e125.

#include <maho/base.h>
#include <maho/rga3/line3.h>
#include <maho/rga3/meet3.h>
#include <maho/rga3/plane3.h>
#include <maho/rga3/point3.h>

namespace maho
{
    namespace cga
    {
        template <typename T> class sphere3;

        template <typename T> class circle3
        {
            vec3<T> _g; // plane
            T _w;
            vec3<T> _v; // direction
            vec3<T> _m; // momentum

        public:
            constexpr circle3() = default;

            constexpr circle3(const vec3<T> &g,
                              T w,
                              const vec3<T> &v,
                              const vec3<T> &m)
                : _g(g), _w(w), _v(v), _m(m)
            {
            }

            constexpr circle3(const circle3 &c)
                : _g(c._g), _w(c._w), _v(c._v), _m(c._m)
            {
            }

            constexpr circle3 &operator=(const circle3 &c)
            {
                _g = c._g;
                _w = c._w;
                _v = c._v;
                _m = c._m;
                return *this;
            }

            constexpr vec3<T> g() const { return _g; }

            constexpr T w() const { return _w; }

            constexpr vec3<T> v() const { return _v; }

            constexpr vec3<T> m() const { return _m; }

            constexpr rga::point3<T> flat_center() const
            {
                return rga::meet(anticarrier(), carrier());
            }

            constexpr rga::plane3<T> carrier() const
            {
                return rga::plane3<T>(_g, _w);
            }

            constexpr rga::line3<T> anticarrier() const
            {
                return rga::line3<T>(_g, _v);
            }

            constexpr circle3<T> unitized() const;
            constexpr sphere3<T> container() const;

            constexpr T radius() const
            {
                auto num = length2(_v) - _w * _w + 2 * (dot(_g, _m));
                auto den = length2(_g);
                return sqrt(num / den);
            }
        };
    }
}

#include <maho/cga3/meet3.h>
#include <maho/cga3/sphere3.h>

namespace maho
{
    namespace cga
    {
        template <typename T> constexpr circle3<T> circle3<T>::unitized() const
        {
            auto car = carrier();
            auto con = container();
            return meet(car, con);
        }

        template <typename T> constexpr sphere3<T> circle3<T>::container() const
        {
            auto u = -_g.norm2();
            auto v = cross(_g, _v) - _g * _w;
            auto w = dot(_g, _m) - _w * _w;
            return sphere3<T>(u, v, w);
        }
    }
}

#endif // MAHO_CGA_CIRCLE3_H