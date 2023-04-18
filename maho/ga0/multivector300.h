#ifndef MAHO_MULTIVECTOR_300_H
#define MAHO_MULTIVECTOR_300_H

// TODO: Need to check all formulas.
// Only form prototypes for now.

namespace maho
{
    class E
    {
        double _s;
    };

    class E1
    {
        double _s;
    };

    class E2
    {
        double _s;
    };

    class E3
    {
        double _s;
    };

    class E12
    {
        double _s;
    };

    class E31
    {
        double _s;
    };

    class E23
    {
        double _s;
    };

    class E321
    {
        double _s;
    };

    static inline E prod(E a, E b) { return E(a.s() * b.s()); }
    static inline E prod(E1 a, E1 b) { return E(a.s() * b.s()); }
    static inline E prod(E2 a, E2 b) { return E(a.s() * b.s()); }
    static inline E prod(E3 a, E3 b) { return E(a.s() * b.s()); }
    static inline E prod(E12 a, E12 b) { return E(a.s() * b.s()); }
    static inline E prod(E31 a, E31 b) { return E(a.s() * b.s()); }
    static inline E prod(E23 a, E23 b) { return E(a.s() * b.s()); }
    static inline E prod(E321 a, E321 b) { return E(a.s() * b.s()); }

    static inline E1 prod(E a, E1 b) { return a.s() * b.s(); }
    static inline E1 prod(E1 a, E b) { return a.s() * b.s(); }
    static inline E2 prod(E a, E2 b) { return a.s() * b.s(); }
    static inline E2 prod(E2 a, E b) { return a.s() * b.s(); }
    static inline E3 prod(E a, E3 b) { return a.s() * b.s(); }
    static inline E3 prod(E3 a, E b) { return a.s() * b.s(); }

    static inline E1 prod(E321 a, E23 b) { return a.s() * b.s(); }
    static inline E1 prod(E23 a, E321 b) { return a.s() * b.s(); }
    static inline E2 prod(E321 a, E31 b) { return a.s() * b.s(); }
    static inline E2 prod(E31 a, E321 b) { return a.s() * b.s(); }
    static inline E3 prod(E321 a, E12 b) { return a.s() * b.s(); }
    static inline E3 prod(E12 a, E321 b) { return a.s() * b.s(); }

    static inline E12 prod(E1 e1, E2 e2) { return E12(e1.s() * e2.s()); }
    static inline E12 prod(E2 e2, E1 e1) { return E12(-e1.s() * e2.s()); }
    static inline E31 prod(E1 e1, E3 e3) { return E31(-e1.s() * e3.s()); }
    static inline E31 prod(E3 e3, E1 e1) { return E31(e1.s() * e3.s()); }
    static inline E23 prod(E2 e2, E3 e3) { return E23(e2.s() * e3.s()); }
    static inline E23 prod(E3 e3, E2 e2) { return E23(-e2.s() * e3.s()); }

    static inline E12 prod(E321 e321, E3 e3) { return E12(-e321.s() * e3.s()); }
    static inline E12 prod(E3 e3, E321 e321) { return E12(-e321.s() * e3.s()); }
    static inline E31 prod(E321 e321, E2 e2) { return E31(-e321.s() * e2.s()); }
    static inline E31 prod(E2 e2, E321 e321) { return E31(-e321.s() * e2.s()); }
    static inline E23 prod(E321 e321, E1 e1) { return E23(-e321.s() * e1.s()); }
    static inline E23 prod(E1 e1, E321 e321) { return E23(-e321.s() * e1.s()); }

    static inline E321 prod(E3 e3, E12 e12) { return E321(-e12.s() * e3.s()); }
    static inline E321 prod(E12 e12, E3 e3) { return E321(-e12.s() * e3.s()); }
    static inline E321 prod(E2 e2, E31 e31) { return E321(-e31.s() * e2.s()); }
    static inline E321 prod(E31 e31, E2 e2) { return E321(-e31.s() * e2.s()); }
    static inline E321 prod(E1 e1, E23 e23) { return E321(-e23.s() * e1.s()); }
    static inline E321 prod(E23 e23, E1 e1) { return E321(-e23.s() * e1.s()); }

    class scalar300
    {
        E _e;
    };

    class vector300
    {
        E1 _e1;
        E2 _e2;
        E3 _e3;
    };

    class bivector300
    {
        E12 _e12;
        E31 _e31;
        E23 _e23;
    };

    class trivector300
    {
        E321 _e321;
    };

    class scalar300_bivector300
    {
        scalar300 _s;
        bivector300 _b;
    };

    class scalar300_vector300
    {
        scalar300 _s;
        vector300 _v;
    };

    static inline scalar300 prod(const scalar300 &a, const scalar300 &b)
    {
        return {a.e() * b.e()};
    }

    template <typename A, typename B>
    static inline auto prod(const A &a, const B &b)
    {
        auto i = inner_prod(a, b);
        auto o = outer_prod(a, b);
        return i + o;
    }

    class multivector300
    {
        E _e;
        E1 _e1;
        E2 _e2;
        E3 _e3;
        E12 _e12;
        E31 _e31;
        E23 _e23;
        E321 _e321;

    public:
        multivector300()
            : _e(0), _e1(0), _e2(0), _e3(0), _e12(0), _e31(0), _e23(0), _e321(0)
        {
        }
    };

    multivector300 prod(const multivector300 &a, const multivector300 &b)
    {
        auto e = prod(a.e(), b.e()) + prod(a.e1(), b.e1()) +
                 prod(a.e2(), b.e2()) + prod(a.e3(), b.e3()) +
                 prod(a.e12(), b.e12()) + prod(a.e31(), b.e31()) +
                 prod(a.e23(), b.e23()) + prod(a.e321(), b.e321());

        auto e1 = prod(a.e(), b.e1()) + prod(a.e1(), b.e()) +
                  prod(a.e23(), b.e321()) + prod(a.e321(), b.e23()) +
                  prod(a.e3(), b.e12()) + prod(a.e12(), b.e3());

        auto e2 = prod(a.e(), b.e2()) + prod(a.e2(), b.e()) +
                  prod(a.e31(), b.e321()) + prod(a.e321(), b.e31()) +
                  prod(a.e1(), b.e23()) + prod(a.e23(), b.e1());

        auto e3 = prod(a.e(), b.e3()) + prod(a.e3(), b.e()) +
                  prod(a.e12(), b.e321()) + prod(a.e321(), b.e12()) +
                  prod(a.e2(), b.e31()) + prod(a.e31(), b.e2());

        auto e12 = prod(a.e(), b.e12()) + prod(a.e12(), b.e()) +
                   prod(a.e3(), b.e23()) + prod(a.e23(), b.e3()) +
                   prod(a.e31(), b.e321()) + prod(a.e321(), b.e31());

        auto e31 = prod(a.e(), b.e31()) + prod(a.e31(), b.e()) +
                   prod(a.e1(), b.e321()) + prod(a.e321(), b.e1()) +
                   prod(a.e12(), b.e23()) + prod(a.e23(), b.e12());

        auto e23 = prod(a.e(), b.e23()) + prod(a.e23(), b.e()) +
                   prod(a.e2(), b.e321()) + prod(a.e321(), b.e2()) +
                   prod(a.e31(), b.e12()) + prod(a.e12(), b.e31());

        auto e321 = prod(a.e(), b.e321()) + prod(a.e321(), b.e()) +
                    prod(a.e23(), b.e1()) + prod(a.e1(), b.e23()) +
                    prod(a.e12(), b.e2()) + prod(a.e2(), b.e12()) +
                    prod(a.e3(), b.e31()) + prod(a.e31(), b.e3());
    }
};
