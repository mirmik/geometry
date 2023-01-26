#ifndef MAHO_RGA_POINT3_H
#define MAHO_RGA_POINT3_H

/// @file maho/rga3/point3.h

/// @class maho::rga::point3
/// @brief 3D space point in RGA and CGA representation.
///
/// RGA (vector)  : p = x*e1  + y*e2  + z*e3  + w*e4
/// CGA (bivector): p = x*e15 + y*e25 + z*e35 + w*e45

#include <maho/base.h>
#include <maho/ga0/magnitude.h>

namespace maho
{
    namespace rga
    {
        template <class T> class point3
        {
            vec3<T> _xyz;
            T _w;

        public:
            constexpr point3() : _xyz(), _w(1) {}
            constexpr point3(T x, T y, T z) : _xyz(x, y, z), _w(1) {}
            constexpr point3(const vec3<T> &v) : _xyz(v), _w(1) {}

            constexpr point3(T x, T y, T z, T w) : _xyz(x, y, z), _w(w) {}
            constexpr point3(const point3 &p) : _xyz(p._xyz), _w(p._w) {}
            constexpr point3(const vec3<T> &v, T w) : _xyz(v), _w(w) {}

            constexpr vec3<T> xyz() const { return _xyz; }
            constexpr T w() const { return _w; }
            constexpr vec3<T> bulk() const { return _xyz; }
            constexpr T weight() const { return _w; }

            constexpr point3 &operator=(const point3 &p)
            {
                _xyz = p._xyz;
                _w = p._w;
                return *this;
            }

            constexpr point3 &operator=(const vec3<T> &v)
            {
                _xyz = v;
                _w = 1;
                return *this;
            }

            constexpr bool operator==(const point3 &p) const
            {
                return _xyz == p._xyz && _w == p._w;
            }

            constexpr bool operator!=(const point3 &p) const
            {
                return !(*this == p);
            }

            constexpr point3 unitized() const { return point3(_xyz / _w, 1); }

            bool is_infinite() const { return _w == 0; }

            bool is_unitized() const { return _w == 1; }
        };

        template <class T>
        constexpr point3<T> operator+(const point3<T> &p, const vec3<T> &v)
        {
            return point3<T>(p.xyz() + v * p.w(), p.w());
        }
    }
}

namespace std
{
    template <class T>
    std::ostream &operator<<(std::ostream &os, const maho::rga::point3<T> &p)
    {
        os << "(" << p.xyz().x << "," << p.xyz().y << "," << p.xyz().z << ","
           << p.w() << ")";
        return os;
    }
}

#endif // MAHO_RGA_H