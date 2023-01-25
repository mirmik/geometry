#ifndef MAHO_GA1_MAGNITUDE_H
#define MAHO_GA1_MAGNITUDE_H

namespace maho
{
    namespace ga0
    {
        template <typename T> class magnitude
        {
            T _s;
            T _w;

        public:
            constexpr magnitude() : _s(0), _w(0) {}
            constexpr magnitude(T s, T w) : _s(s), _w(w) {}
            constexpr magnitude(const magnitude &m) : _s(m._s), _w(m._w) {}
            constexpr magnitude &operator=(const magnitude &m)
            {
                _s = m._s;
                _w = m._w;
                return *this;
            }

            constexpr T s() const
            {
                return _s;
            }

            constexpr T w() const
            {
                return _w;
            }

            constexpr T &s()
            {
                return _s;
            }

            constexpr T &w()
            {
                return _w;
            }

            constexpr bool operator==(const magnitude &m) const
            {
                return _s == m._s && _w == m._w;
            }

            constexpr bool operator!=(const magnitude &m) const
            {
                return _s != m._s || _w != m._w;
            }

            constexpr magnitude unitized() const
            {
                return magnitude(_s / _w, 1);
            }

            bool is_infinite() const
            {
                return _w == 0;
            }

            bool is_unitized() const
            {
                return _w == 1;
            }
        };
    }
}

namespace std
{
    template <class T>
    std::ostream &operator<<(std::ostream &os, const maho::ga0::magnitude<T> &p)
    {
        os << "(" << p.s() << "," << p.w() << ")";
        return os;
    }
}

#endif