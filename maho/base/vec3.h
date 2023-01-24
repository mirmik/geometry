#ifndef MAHO_BASE_VEC3_H
#define MAHO_BASE_VEC3_H

#include <cmath>

namespace maho
{
    template <class T> class vec3
    {
        T _x, _y, _z;

    public:
        constexpr vec3() : _x(0), _y(0), _z(0) {}
        constexpr vec3(T x, T y, T z) : _x(x), _y(y), _z(z) {}
        constexpr vec3(const vec3 &v) : _x(v._x), _y(v._y), _z(v._z) {}
        constexpr vec3 &operator=(const vec3 &v)
        {
            _x = v._x;
            _y = v._y;
            _z = v._z;
            return *this;
        }

        constexpr T x() const
        {
            return _x;
        }

        constexpr T y() const
        {
            return _y;
        }

        constexpr T z() const
        {
            return _z;
        }

        constexpr T &x()
        {
            return _x;
        }

        constexpr T &y()
        {
            return _y;
        }

        constexpr T &z()
        {
            return _z;
        }

        constexpr bool operator==(const vec3 &v) const
        {
            return _x == v._x && _y == v._y && _z == v._z;
        }

        constexpr bool operator!=(const vec3 &v) const
        {
            return !(*this == v);
        }

        constexpr T norm2() const
        {
            return _x * _x + _y * _y + _z * _z;
        }

        constexpr T norm() const
        {
            return std::sqrt(norm2());
        }
    };
}

namespace std
{
    template <class T> ostream &operator<<(ostream &os, const maho::vec3<T> &v)
    {
        os << "(" << v.x() << "," << v.y() << "," << v.z() << ")";
        return os;
    }
}

#endif // MAHO_BASE_VEC3_H