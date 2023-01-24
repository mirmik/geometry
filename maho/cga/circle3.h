#ifndef MAHO_CGA_CIRCLE3_H
#define MAHO_CGA_CIRCLE3_H

#include <maho/base.h>
#include <maho/rga/line3.h>
#include <maho/rga/meet3.h>
#include <maho/rga/plane3.h>
#include <maho/rga/point3.h>

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

            constexpr vec3<T> g() const
            {
                return _g;
            }

            constexpr T w() const
            {
                return _w;
            }

            constexpr vec3<T> v() const
            {
                return _v;
            }

            constexpr vec3<T> m() const
            {
                return _m;
            }

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
                auto num = _v.norm2() - _w * _w + 2 * (dot(_g, _m));
                auto den = _g.norm2();
                return sqrt(num / den);
            }
        };
    }
}

#include <maho/cga/meet3.h>
#include <maho/cga/sphere3.h>

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