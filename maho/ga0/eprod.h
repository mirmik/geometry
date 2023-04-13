#ifndef MAHO_GA0_EPROD_HE321
#define MAHO_GA0_EPROD_H

namespace maho
{
    E12 prod(const E1 &e1, const E2 &e2) { return E12(e1.s() * e2.s()); }
    E12 prod(const E2 &e1, const E1 &e3) { return E12(-e1.s() * e2.s()); }
    E31 prod(const E1 &e1, const E3 &e3) { return E31(-e1.s() * e3.s()); }
    E31 prod(const E3 &e3, const E1 &e1) { return E31(e1.s() * e3.s()); }
    E23 prod(const E2 &e2, const E3 &e3) { return E23(e2.s() * e3.s()); }
    E23 prod(const E3 &e3, const E2 &e2) { return E23(-e2.s() * e3.s()); }

    E321 prod(const E3 &e3, const E12 &e12) { return E321(-e12.s() * e3.s()); }
    E321 prod(const E12 &e12, const E3 &e3) { return E321(-e12.s() * e3.s()); }
    E321 prod(const E2 &e2, const E31 &e31) { return E321(-e31.s() * e2.s()); }
    E321 prod(const E31 &e31, const E2 &e2) { return E321(-e31.s() * e2.s()); }
    E321 prod(const E1 &e1, const E23 &e23) { return E321(-e23.s() * e1.s()); }
    E321 prod(const E23 &e23, const E1 &e1) { return E321(-e23.s() * e1.s()); }
}

#endif