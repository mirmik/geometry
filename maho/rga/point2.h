#ifndef MAHO_RGA_POINT2_H
#define MAHO_RGA_POINT2_H

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
            constexpr point2(const pnt2<T> &p) : _xy(p), _z(1) {}
            constexpr point2(const vec2<T> &v) : _xy(v), _z(0) {}
            constexpr point2(const vec2<T> &v, T z) : _xy(v), _z(z) {}
            constexpr point2 &operator=(const point2 &p)
            {
                _xy = p._xy;
                _z = p._z;
                return *this;
            }

            constexpr point2 &operator=(const pnt2<T> &p)
            {
                _xy = p;
                _z = 1;
                return *this;
            }

            constexpr point2 &operator=(const vec2<T> &v)
            {
                _xy = v;
                _z = 0;
                return *this;
            }

            constexpr T x() const
            {
                return _xy.x();
            }

            constexpr T y() const
            {
                return _xy.y();
            }

            constexpr T z() const
            {
                return _z;
            }
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