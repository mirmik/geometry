#ifndef MAHO_RGA_POINT2_H
#define MAHO_RGA_POINT2_H

#include <iostream>
#include <maho/base.h>

namespace maho
{
    namespace rga
    {
        template <class T> class point2
        {
            vec2<T> _xy;
            T _z;

        public:
            constexpr point2() : _xy(), _z(1) {}
            constexpr point2(T x, T y) : _xy(x, y), _z(1) {}
            constexpr point2(T x, T y, T z) : _xy(x, y), _z(z) {}
            constexpr point2(const point2 &p) : _xy(p._xy), _z(p._z) {}
            constexpr point2(const vec2<T> &v) : _xy(v), _z(1) {}
            constexpr point2(const vec2<T> &v, T w) : _xy(v), _z(w) {}
            constexpr point2 &operator=(const point2 &p)
            {
                _xy = p._xy;
                _z = p._z;
                return *this;
            }

            constexpr point2 &operator=(const vec2<T> &v)
            {
                _xy = v;
                _z = 0;
                return *this;
            }

            constexpr T x() const { return _xy.x; }

            constexpr T y() const { return _xy.y; }

            constexpr T z() const { return _xy.z; }

            constexpr vec2<T> xyz() const { return _xy; }

            constexpr vec2<T> bulk() const { return _xy; }

            constexpr T weight() const { return _z; }

            constexpr bool operator==(const point2 &p) const
            {
                return _xy == p._xy && _z == p._z;
            }

            constexpr bool operator!=(const point2 &p) const
            {
                return !(*this == p);
            }

            constexpr point2 unitized() const { return point2(_xy / _z, 1); }
        };
    }

}

namespace std
{
    template <class T>
    std::ostream &operator<<(std::ostream &os, const maho::rga::point2<T> &p)
    {
        os << "(" << p.x() << "," << p.y() << "," << p.z() << ")";
        return os;
    }
}

#endif // MAHO_RGA_H