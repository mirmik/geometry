#ifndef MAHO_BASE_VEC4_H
#define MAHO_BASE_VEC4_H

#include <cmath>

namespace maho
{
    template <class T> class vec4
    {
        T _x, _y, _z, _w;

    public:
        constexpr vec4() : _x(0), _y(0), _z(0), _w(0) {}
        constexpr vec4(T x, T y, T z, T w) : _x(x), _y(y), _z(z), _w(w) {}
        constexpr vec4(const vec4 &v) : _x(v._x), _y(v._y), _z(v._z), _w(v._w)
        {
        }
        constexpr vec4 &operator=(const vec4 &v)
        {
            _x = v._x;
            _y = v._y;
            _z = v._z;
            _w = v._w;
            return *this;
        }

        constexpr T x() const { return _x; }

        constexpr T y() const { return _y; }

        constexpr T z() const { return _z; }

        constexpr T w() const { return _w; }

        constexpr T &x() { return _x; }

        constexpr T &y() { return _y; }

        constexpr T &z() { return _z; }

        constexpr T &w() { return _w; }

        constexpr bool operator==(const vec4 &v) const
        {
            return _x == v._x && _y == v._y && _z == v._z && _w == v._w;
        }

        constexpr bool operator!=(const vec4 &v) const { return !(*this == v); }

        constexpr T norm2() const
        {
            return _x * _x + _y * _y + _z * _z + _w * _w;
        }

        constexpr T norm() const { return std::sqrt(norm2()); }
    };
}

namespace std
{
    template <class T> ostream &operator<<(ostream &os, const maho::vec4<T> &v)
    {
        os << "(" << v.x() << "," << v.y() << "," << v.z() << v.w() << ")";
        return os;
    }
}

#endif // MAHO_BASE_VEC4_H