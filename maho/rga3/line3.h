#ifndef MAHO_RGA_LINE3_H
#define MAHO_RGA_LINE3_H

/// @file maho/rga3/line3.h

/// @class maho::rga::line3
/// @brief Line in 3D space.
///
/// RGA (bivector) : l = vx*e41 + vy*e42 + vz*e43 + mx*e23 + my*e31 + mz*e12.
/// CGA (trivector): l = vx*e415 + vy*e425 + vz*e435 + mx*e235 + my*e315 +
/// mz*e125.

#include <maho/base.h>

namespace maho
{
    namespace rga
    {
        template <class T> class point3;
        template <class T> class line3
        {
            vec3<T> _direction = {};
            vec3<T> _momentum = {};

        public:
            constexpr line3() = default;

            constexpr line3(T x, T y, T z, T w, T u, T v)
                : _direction(x, y, z), _momentum(w, u, v)
            {
            }

            constexpr line3(const vec3<T> &direction, const vec3<T> &momentum)
                : _direction(direction), _momentum(momentum)
            {
            }

            constexpr line3(const line3 &l)
                : _direction(l._direction), _momentum(l._momentum)
            {
            }

            constexpr vec3<T> direction() const { return _direction; }
            constexpr vec3<T> momentum() const { return _momentum; }
            constexpr vec3<T> weight() const { return _direction; }
            constexpr vec3<T> bulk() const { return _momentum; }
            constexpr vec3<T> v() const { return _direction; }
            constexpr vec3<T> m() const { return _momentum; }

            constexpr line3 &operator=(const line3 &l)
            {
                _direction = l._direction;
                _momentum = l._momentum;
                return *this;
            }

            constexpr line3 unitized() const
            {
                auto n = _direction.norm();
                return line3(_direction / n, _momentum / n);
            }

            constexpr line3 operator-() const
            {
                return line3(-_direction, -_momentum);
            }

            bool is_infinite() { return _direction == vec3<T>{0, 0, 0}; }

            /*bool is_unitized(T eps = 1e-5) const
            {
                return _direction.norm2() < eps;
            }*/

            static constexpr line3 OX() { return line3(1, 0, 0, 0, 0, 0); }
            static constexpr line3 OY() { return line3(0, 1, 0, 0, 0, 0); }
            static constexpr line3 OZ() { return line3(0, 0, 1, 0, 0, 0); }
        };

        template <class T> constexpr line3<T> OX() { return line3<T>::OX(); }

        template <class T> constexpr line3<T> OY() { return line3<T>::OY(); }

        template <class T> constexpr line3<T> OZ() { return line3<T>::OZ(); }
    }
}

#endif