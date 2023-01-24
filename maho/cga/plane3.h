#ifndef MAHO_CGA_PLANE3_H
#define MAHO_CGA_PLANE3_H

#include <maho/base.h>
namespace maho
{
    namespace cga
    {
        template <class T> class plane3
        {
            vec3<T> _normal;
            T _negdist;

        public:
            constexpr plane3() : _normal(), _negdist(0) {}
            constexpr plane3(T x, T y, T z, T w) : _normal(x, y, z), _negdist(w)
            {
            }
            constexpr plane3(const vec3<T> &normal, T negdist)
                : _normal(normal), _negdist(negdist)
            {
            }

            constexpr plane3(const plane3 &p)
                : _normal(p._normal), _negdist(p._negdist)
            {
            }

            constexpr plane3 &operator=(const plane3 &p)
            {
                _normal = p._normal;
                _negdist = p._negdist;
                return *this;
            }

            constexpr vec3<T> normal() const
            {
                return _normal;
            }

            constexpr T weight() const
            {
                return _negdist;
            }

            constexpr plane3 unitized() const
            {
                auto n = _normal.norm();
                return plane3(_normal / n, _negdist / n);
            }

            constexpr vec3<T> xyz() const
            {
                return _normal;
            }

            constexpr T w() const
            {
                return _negdist;
            }
        };
    }
}

#endif // MAHO_CGA_PLANE3_H