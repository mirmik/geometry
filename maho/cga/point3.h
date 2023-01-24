#ifndef MAHO_CGA_H
#define MAHO_CGA_H

#include <maho/base.h>

namespace maho
{
    namespace cga
    {
        template <class T> class point3
        {
            vec3<T> _xyz;
            T _w;

        public:
            constexpr point3() : _xyz(), _w(1) {}
            constexpr point3(T x, T y, T z) : _xyz(x, y, z), _w(1) {}
            constexpr point3(T x, T y, T z, T w) : _xyz(x, y, z), _w(w) {}
            constexpr point3(const point3 &p) : _xyz(p._xyz), _w(p._w) {}
            constexpr point3(const pnt3<T> &p) : _xyz(p), _w(1) {}
            constexpr point3(const vec3<T> &v) : _xyz(v), _w(0) {}
            constexpr point3(const vec3<T> &v, T w) : _xyz(v), _w(w) {}
            constexpr point3 &operator=(const point3 &p)
            {
                _xyz = p._xyz;
                _w = p._w;
                return *this;
            }

            constexpr point3 &operator=(const pnt3<T> &p)
            {
                _xyz = p;
                _w = 1;
                return *this;
            }

            constexpr point3 &operator=(const vec3<T> &v)
            {
                _xyz = v;
                _w = 0;
                return *this;
            }

            constexpr T x() const
            {
                return _xyz.x();
            }

            constexpr T y() const
            {
                return _xyz.y();
            }

            constexpr T z() const
            {
                return _xyz.z();
            }

            constexpr T w() const
            {
                return _w;
            }

            constexpr T &x()
            {
                return _xyz.x();
            }

            constexpr T &y()
            {
                return _xyz.y();
            }

            constexpr T &z()
            {
                return _xyz.z();
            }

            constexpr T &w()
            {
                return _w;
            }

            constexpr vec3<T> xyz() const
            {
                return _xyz;
            }

            constexpr vec3<T> &xyz()
            {
                return _xyz;
            }

            constexpr vec3<T> bulk() const
            {
                return _xyz;
            }

            constexpr vec3<T> &bulk()
            {
                return _xyz;
            }

            constexpr T weight() const
            {
                return _w;
            }

            constexpr T &weight()
            {
                return _w;
            }

            constexpr bool operator==(const point3 &p) const
            {
                return _xyz == p._xyz && _w == p._w;
            }

            constexpr bool operator!=(const point3 &p) const
            {
                return !(*this == p);
            }

            constexpr point3 unitized() const
            {
                return point3(_xyz.unitized(), _w);
            }
        };
    }

}

namespace std
{
    template <class T>
    std::ostream &operator<<(std::ostream &os, const maho::cga::point3<T> &p)
    {
        os << "(" << p.x() << "," << p.y() << "," << p.z() << "," << p.w()
           << ")";
        return os;
    }
}

#endif // MAHO_CGA_H