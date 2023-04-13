#ifndef MAHO_RGA3_MOTOR3_H
#define MAHO_RGA3_MOTOR3_H

// General motor form.

#include <maho/base.h>
//#include <maho/base/pose3.h>
#include <maho/rga3/line3.h>
#include <maho/rga3/point3.h>

namespace maho
{
    namespace rga
    {
        template <class T> class screw_line3
        {
            line3<T> _l;
            T _phi, _d;

        public:
            constexpr screw_line3() : _l(), _phi(0), _d(0) {}
            screw_line3(const line3<T> &l, T phi, T d) : _l(l), _phi(phi), _d(d)
            {
            }

            constexpr const line3<T> &line() const { return _l; }
            constexpr T angle() const { return _phi; }
            constexpr T distance() const { return _d; }

            constexpr T steps() const { return _phi / 2 / M_PI; }
            constexpr T step_distance() const { return _d / steps(); }

            constexpr T length_of_screw_step_with_radius(T r) const
            {
                T circlen = 2 * M_PI * r;
                T stepheight = step_distance();
                T stepwidth = sqrt(circlen * circlen + stepheight * stepheight);
                return stepwidth;
            }

            constexpr T length_with_radius(T r) const
            {
                return length_of_screw_step_with_radius(r) * steps();
            }

            constexpr T length_for_point(const point3<T> &r) const;
        };

        template <typename T> class motor3
        {
            vec4<T> _v; // rotation part
            vec4<T> _m; // translation part

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

            // Factorization. Get rotation part. Must be unitized.
            constexpr vec4<T> rotation() const { return _v; }

            // Factorization. Get translation part. Must be unitized.
            constexpr vec3<T> translation() const
            {
                auto xyz = cross(_v.xyz(), _m.xyz()) + _m.xyz() * _v.w() -
                           _v.xyz() * _m.w();
                return xyz;
            }

            constexpr const vec4<T> &v() const { return _v; }
            constexpr const vec4<T> &m() const { return _m; }
            constexpr const vec4<T> &weight() const { return _v; }
            constexpr const vec4<T> &bulk() const { return _m; }

            constexpr screw_line3<T> screw_line() const
            {
                auto phi = acos(_v.w);
                auto d = -(_m.w / sin(phi));
                auto lv = _v.xyz() / sin(phi);
                auto lm = (_m.xyz() - lv * d * cos(phi)) / sin(phi);
                return {line3<T>(lv, lm), phi * 2, d * 2};
            }
        };

        template <typename T>
        motor3<T> motor3_from_rotation_quat(const vec4<T> &v)
        {
            return motor3<T>{v, vec4<T>(0, 0, 0, 0)};
        }

        template <typename T>
        motor3<T> motor3_from_rotation_vector(const vec3<T> &e)
        {
            auto u = normalize(e);
            auto a = length(e);
            auto v = linalg::rotation_quat(u, a);
            auto m = vec4(0, 0, 0, 0);
            return motor3<T>{v, m};
        }

        template <typename T>
        motor3<T> motor3_from_rotation_dirang(const vec3<T> &d, T a)
        {
            auto u = normalize(d);
            auto v = linalg::rotation_quat(u, a);
            auto m = vec4<T>(0, 0, 0, 0);
            return motor3<T>{v, m};
        }

        template <typename T>
        motor3<T> motor3_from_translation_vector(const vec3<T> &t)
        {
            auto v = vec4<T>(0, 0, 0, 1);
            auto m = vec4<T>(t / 2, 0);
            return motor3<T>{v, m};
        }

        template <typename T>
        vec4<T> realbivec3_prod_dualbivec3(const vec4<T> &a, const vec4<T> &b)
        {
            auto xyz = -linalg::cross(a.xyz(), b.xyz()) + a.xyz() * b.w +
                       b.xyz() * a.w;
            auto w = 0 - a.x * b.x - a.y * b.y - a.z * b.z + a.w * b.w;
            return vec4<T>(xyz.x, xyz.y, xyz.z, w);
        }

        template <typename T>
        vec4<T> dualbivec3_prod_realbivec3(const vec4<T> &a, const vec4<T> &b)
        {
            auto xyz = +linalg::cross(a.xyz(), b.xyz()) + a.xyz() * b.w +
                       b.xyz() * a.w;
            auto w = 0 - a.x * b.x - a.y * b.y - a.z * b.z + a.w * b.w;
            return vec4<T>(xyz.x, xyz.y, xyz.z, w);
        }

        template <typename T>
        vec4<T> dualbivec3_antiprod_realbivec3(const vec4<T> &a,
                                               const vec4<T> &b)
        {
            auto xyz = -linalg::cross(a.xyz(), b.xyz()) + a.xyz() * b.w +
                       b.xyz() * a.w;
            auto w = 0 - linalg::dot(a.xyz(), b.xyz()) + a.w * b.w;
            return vec4<T>(xyz, w);
        }

        template <typename T>
        vec4<T> realbivec3_antiprod_dualbivec3(const vec4<T> &a,
                                               const vec4<T> &b)
        {
            auto xyz = +linalg::cross(a.xyz(), b.xyz()) + a.xyz() * b.w +
                       b.xyz() * a.w;
            auto w = 0 - linalg::dot(a.xyz(), b.xyz()) + a.w * b.w;
            return vec4<T>(xyz, w);
        }

        template <typename T>
        vec4<T> realbivec3_prod_realbivec3(const vec4<T> &a, const vec4<T> &b)
        {
            return linalg::qmul(a, b);
        }

        template <typename T>
        vec4<T> dualbivec3_antiprod_dualbivec3(const vec4<T> &a,
                                               const vec4<T> &b)
        {
            return linalg::qmul(a, b);
        }

        template <typename T>
        motor3<T> operator*(const motor3<T> &a, const motor3<T> &b)
        {
            auto vv = dualbivec3_antiprod_dualbivec3(a.v(), b.v());
            auto vm = dualbivec3_antiprod_realbivec3(a.v(), b.m());
            auto mv = realbivec3_antiprod_dualbivec3(a.m(), b.v());
            return motor3<T>{vv, vm + mv};
        }

        template <typename T>
        point3<T> transform(const motor3<T> &Q, const point3<T> &p)
        {
            auto &v = Q.v();
            auto &m = Q.m();
            auto x =
                (1 - 2 * v.y * v.y - 2 * v.z * v.z) * p.x() +
                2 * (v.x * v.y - v.w * v.z) * p.y() +
                2 * (v.x * v.z + v.w * v.y) * p.z() +
                2 * (v.y * m.z - v.z * m.y + v.w * m.x - v.x * m.w) * p.w();
            auto y =
                (1 - 2 * v.x * v.x - 2 * v.z * v.z) * p.y() +
                2 * (v.y * v.z - v.w * v.x) * p.z() +
                2 * (v.y * v.x + v.w * v.z) * p.x() +
                2 * (v.z * m.x - v.x * m.z + v.w * m.y - v.y * m.w) * p.w();
            auto z =
                (1 - 2 * v.x * v.x - 2 * v.y * v.y) * p.z() +
                2 * (v.x * v.z - v.w * v.y) * p.x() +
                2 * (v.y * v.z + v.w * v.x) * p.y() +
                2 * (v.x * m.y - v.y * m.x + v.w * m.z - v.z * m.w) * p.w();
            auto w = p.w();
            return point3<T>(x, y, z, w);
        }
    }
}

namespace std
{
    template <class T>
    std::ostream &operator<<(std::ostream &os, const maho::rga::motor3<T> &p)
    {
        os << "motor3(v:" << p.v() << ",m:" << p.m() << ")";
        return os;
    }
    template <class T>
    std::ostream &operator<<(std::ostream &os,
                             const maho::rga::screw_line3<T> &sl)
    {
        os << "screw_line3(" << sl.line() << ",phi:" << sl.angle()
           << ",d:" << sl.distance() << ")";
        return os;
    }
}

#include <maho/rga3/distance3.h>

namespace maho
{
    namespace rga
    {
        template <class T>
        constexpr T screw_line3<T>::length_for_point(const point3<T> &p) const
        {

            auto dist_to_point = maho::rga::distance<T>(p, line());
            return length_with_radius(dist_to_point.value());
        }

    }
}

#endif // MAHO_RGA3_MOTOR3_H