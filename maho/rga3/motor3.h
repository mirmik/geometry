#ifndef MAHO_RGA3_MOTOR3_H
#define MAHO_RGA3_MOTOR3_H

#include <maho/base.h>

namespace maho
{
    namespace rga
    {
        template <typename T> class motor3
        {
            vec4<T> _v;
            vec4<T> _m;

        public:
            motor3() : _v(0, 0, 0, 1), _m(0, 0, 0, 0) {}
            motor3(const vec4<T> &v, const vec4<T> &m) : _v(v), _m(m) {}
            motor3(const motor3 &m) : _v(m._v), _m(m._m) {}
            motor3 &operator=(const motor3 &m)
            {
                _v = m._v;
                _m = m._m;
                return *this;
            }

            constexpr vec4<T> rotation() const { return _v; }
            constexpr vec3<T> translation() const
            {
                auto xyz = cross(_v.xyz(), _m.xyz()) + _m.xyz() * _v.w() -
                           _v.xyz() * _m.w();
                return xyz;
            }

            constexpr vec4<T> &v() const { return _v; }
            constexpr vec4<T> &m() const { return _m; }
            constexpr vec4<T> &weight() const { return _v; }
            constexpr vec4<T> &bulk() const { return _m; }
        };
    }
}

#endif // MAHO_RGA3_MOTOR3_H