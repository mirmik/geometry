#ifndef MAHO_CGA_LINE3_H
#define MAHO_CGA_LINE3_H

#include <maho/base.h>

namespace maho
{
    namespace cga
    {
        // Line is bivector in CL(3,1) and trivector in CL(4,1).
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

            constexpr line3 &operator=(const line3 &l)
            {
                _direction = l._direction;
                _momentum = l._momentum;
                return *this;
            }

            constexpr vec3<T> direction() const
            {
                return _direction;
            }

            constexpr vec3<T> momentum() const
            {
                return _momentum;
            }

            constexpr vec3<T> v() const
            {
                return _direction;
            }

            constexpr vec3<T> m() const
            {
                return _momentum;
            }

            constexpr line3 unitized() const
            {
                auto n = _direction.norm();
                return line3(_direction / n, _momentum / n);
            }
        };
    }
}

#endif