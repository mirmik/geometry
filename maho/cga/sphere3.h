#ifndef MAHO_CGA_SPHERE3_H
#define MAHO_CGA_SPHERE3_H

// Based on https://conformalgeometricalgebra.org/wiki/index.php?title=Sphere

#include <maho/base.h>

namespace maho
{
    namespace cga
    {
        template <typename T> class sphere3
        {
            T _u;
            vec3<T> _xyz;
            T _w;

        public:
            constexpr sphere3() = default;
            constexpr sphere3(T u, const vec3<T> &xyz, T w)
                : _u(u), _xyz(xyz), _w(w)
            {
            }
            constexpr sphere3(const sphere3 &s)
                : _u(s._u), _xyz(s._xyz), _w(s._w)
            {
            }

            // Constructs a sphere from a center and a radius.
            static constexpr sphere3 construct(const vec3<T> &center, T radius)
            {
                auto c2 = center.norm2();
                auto r2 = radius * radius;
                return sphere3(-1, center, -(c2 - r2) / 2);
            }

            constexpr sphere3 &operator=(const sphere3 &s)
            {
                _xyz = s._xyz;
                _w = s._w;
                _u = s._u;
                return *this;
            }

            constexpr vec3<T> xyz() const
            {
                return _xyz;
            }

            constexpr T w() const
            {
                return _w;
            }

            constexpr T u() const
            {
                return _u;
            }

            constexpr sphere3 unitized() const
            {
                return sphere3(-_xyz / _u, -_w / _u, -1);
            }

            // Returns the center of the sphere if unitized.
            constexpr vec3<T> center() const
            {
                return _xyz;
            }

            // Returns the radius of the sphere if unitized.
            // Equation: _w = - (p^2 - r^2) / 2
            //         : -2*_w = p^2 - r^2
            //         : r^2 = p^2 + 2*_w
            //         : r = sqrt(p^2 + 2*_w)
            constexpr T radius() const
            {
                auto p2 = _xyz.norm2();
                return std::sqrt(p2 + 2 * _w);
            }
        };
    }
}

#endif // MAHO_CGA_SPHERE3_H