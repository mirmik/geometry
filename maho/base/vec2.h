#ifndef MAHO_BASE_VEC2_H
#define MAHO_BASE_VEC2_H

#include <cmath>
#include <ostream>

namespace maho
{
    template <class T> class vec2
    {
        T _x, _y;

    public:
        constexpr vec2() : _x(0), _y(0) {}
        constexpr vec2(T x, T y, T z) : _x(x), _y(y) {}
        constexpr vec2(const vec3 &v) : _x(v._x), _y(v._y) {}
        constexpr vec2 &operator=(const vec3 &v)
        {
            _x = v._x;
            _y = v._y;
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

        constexpr T &x()
        {
            return _x;
        }

        constexpr T &y()
        {
            return _y;
        }

        constexpr bool operator==(const vec2 &v) const
        {
            return _x == v._x && _y == v._y;
        }

        constexpr bool operator!=(const vec2 &v) const
        {
            return !(*this == v);
        }

        constexpr T norm2() const
        {
            return _x * _x + _y * _y;
        }

        constexpr T norm() const
        {
            return std::sqrt(norm2());
        }
    };
}

namespace std
{
    template <class T> ostream &operator<<(ostream &os, const maho::vec2<T> &v)
    {
        os << "(" << v.x() << "," << v.y() < < < < ")";
        return os;
    }
}

#endif // MAHO_BASE_VEC3_H