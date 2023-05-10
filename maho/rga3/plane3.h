#ifndef MAHO_RGA_PLANE3_H
#define MAHO_RGA_PLANE3_H

/// @file maho/rga3/plane3.h

/// @class maho::rga::plane3
/// @brief 3D space plane in RGA and CGA representation.
///
/// RGA (trivector)  : g = x*e423 + y*e431 + z*e412 + w*e321
/// CGA (quadvector) : g = x*e4235 + y*e4315 + z*e4125 + w*e3215

#include <maho/base.h>
namespace maho
{
    namespace rga
    {
        template <class T> class line3;

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
                auto n = length(_normal);
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

            static constexpr plane3 OXY()
            {
                return plane3(0, 0, 1, 0);
            }

            static constexpr plane3 OXZ()
            {
                return plane3(0, 1, 0, 0);
            }

            static constexpr plane3 OYZ()
            {
                return plane3(1, 0, 0, 0);
            }

            bool is_infinite() const
            {
                return _normal == vec3<T>{0, 0, 0};
            }

            /*bool is_unitized(T eps = 1e-5) const
            {
                return _normal.norm2() < eps;
            }*/
        };

        template <class T> constexpr plane3<T> OXY()
        {
            return plane3<T>::OXY();
        }

        template <class T> constexpr plane3<T> OXZ()
        {
            return plane3<T>::OXZ();
        }

        template <class T> constexpr plane3<T> OYZ()
        {
            return plane3<T>::OYZ();
        }
    }
}

#endif // MAHO_RGA_PLANE3_H