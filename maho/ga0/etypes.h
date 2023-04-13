#ifndef MAHO_GA300_TYPES_H
#define MAHO_GA300_TYPES_H

namespace maho
{
    class E1
    {
        double _s;

    public:
        constexpr E1() : _s(0) {}
        constexpr E1(double s) : _s(s) {}
        constexpr E1(const E1 &e) : _s(e._s) {}
        constexpr E1 &operator=(const E1 &e)
        {
            _s = e._s;
            return *this;
        }
        constexpr double s() const { return _s; }
        constexpr double &s() { return _s; }
        constexpr bool operator==(const E1 &e) const { return _s == e._s; }
        constexpr bool operator!=(const E1 &e) const { return _s != e._s; }
    };

    class E2
    {
        double _s;

    public:
        constexpr E2() : _s(0) {}
        constexpr E2(double s) : _s(s) {}
        constexpr E2(const E2 &e) : _s(e._s) {}
        constexpr E2 &operator=(const E2 &e)
        {
            _s = e._s;
            return *this;
        }
        constexpr double s() const { return _s; }
        constexpr double &s() { return _s; }
        constexpr bool operator==(const E2 &e) const { return _s == e._s; }
        constexpr bool operator!=(const E2 &e) const { return _s != e._s; }
    };

    class E3
    {
        double _s;

    public:
        constexpr E3() : _s(0) {}
        constexpr E3(double s) : _s(s) {}
        constexpr E3(const E3 &e) : _s(e._s) {}
        constexpr E3 &operator=(const E3 &e)
        {
            _s = e._s;
            return *this;
        }
        constexpr double s() const { return _s; }
        constexpr double &s() { return _s; }
        constexpr bool operator==(const E3 &e) const { return _s == e._s; }
        constexpr bool operator!=(const E3 &e) const { return _s != e._s; }
    };

    class E23
    {
        double _s;

    public:
        constexpr E23() : _s(0) {}
        constexpr E23(double s) : _s(s) {}
        constexpr E23(const E23 &e) : _s(e._s) {}
        constexpr E23 &operator=(const E23 &e)
        {
            _s = e._s;
            return *this;
        }
        constexpr double s() const { return _s; }
        constexpr double &s() { return _s; }
        constexpr bool operator==(const E23 &e) const { return _s == e._s; }
        constexpr bool operator!=(const E23 &e) const { return _s != e._s; }
    };

    class E31
    {
        double _s;

    public:
        constexpr E31() : _s(0) {}
        constexpr E31(double s) : _s(s) {}
        constexpr E31(const E31 &e) : _s(e._s) {}
        constexpr E31 &operator=(const E31 &e)
        {
            _s = e._s;
            return *this;
        }
        constexpr double s() const { return _s; }
        constexpr double &s() { return _s; }
        constexpr bool operator==(const E31 &e) const { return _s == e._s; }
        constexpr bool operator!=(const E31 &e) const { return _s != e._s; }
    };

    class E12
    {
        double _s;

    public:
        constexpr E12() : _s(0) {}
        constexpr E12(double s) : _s(s) {}
        constexpr E12(const E12 &e) : _s(e._s) {}
        constexpr E12 &operator=(const E12 &e)
        {
            _s = e._s;
            return *this;
        }
        constexpr double s() const { return _s; }
        constexpr double &s() { return _s; }
        constexpr bool operator==(const E12 &e) const { return _s == e._s; }
        constexpr bool operator!=(const E12 &e) const { return _s != e._s; }
    };

    class E321
    {
        double _s;

    public:
        constexpr E321() : _s(0) {}
        constexpr E321(double s) : _s(s) {}
        constexpr E321(const E321 &e) : _s(e._s) {}
        constexpr E321 &operator=(const E321 &e)
        {
            _s = e._s;
            return *this;
        }
        constexpr double s() const { return _s; }
        constexpr double &s() { return _s; }
        constexpr bool operator==(const E321 &e) const { return _s == e._s; }
        constexpr bool operator!=(const E321 &e) const { return _s != e._s; }
    };

    template <class... Args> class EUnion
    {
    };

    template <> class EUnion<>
    {
    };

    template <class T, class... Args>
    class EUnion<T, Args...> : public EUnion<Args...>
    {
        T _t;
    };
}

#endif