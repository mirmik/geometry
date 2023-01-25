#ifndef MAHO_RGA_PLANE3_H
#define MAHO_RGA_PLANE3_H

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

            // Construct a plane from a line and a direction vector.
            constexpr static plane3 construct(const line3<T> &l,
                                              const vec3<T> &direction);
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

#include <maho/rga3/line3.h>
#include <maho/rga3/projection3.h>

namespace maho
{
    namespace rga
    {
        template <class T>
        constexpr plane3<T> plane3<T>::construct(const line3<T> &l,
                                                 const vec3<T> &direction)
        {
            // Use the projection of the line to the origin to get point on the
            // plane.
            // TODO: Simpilify this.
            auto p = project_to_origin(l) + direction;
            return join(l, p);
        }
    }
}

#endif // MAHO_RGA_PLANE3_H