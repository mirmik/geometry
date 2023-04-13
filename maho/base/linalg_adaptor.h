#ifndef MAHO_BASE_LINALG_ADAPTOR_H
#define MAHO_BASE_LINALG_ADAPTOR_H

#include <maho/base/linalg.h>

namespace maho
{
    using namespace linalg;

    template <class T> using vec2 = linalg::vec<T, 2>;
    template <class T> using vec3 = linalg::vec<T, 3>;
    template <class T> using vec4 = linalg::vec<T, 4>;
    template <class T> using mat22 = linalg::mat<T, 2, 2>;
    template <class T> using mat23 = linalg::mat<T, 2, 3>;
    template <class T> using mat24 = linalg::mat<T, 2, 4>;
    template <class T> using mat32 = linalg::mat<T, 3, 2>;
    template <class T> using mat33 = linalg::mat<T, 3, 3>;
    template <class T> using mat34 = linalg::mat<T, 3, 4>;
    template <class T> using mat42 = linalg::mat<T, 4, 2>;
    template <class T> using mat43 = linalg::mat<T, 4, 3>;
    template <class T> using mat44 = linalg::mat<T, 4, 4>;
}

namespace linalg
{
    using linalg::ostream_overloads::operator<<;
}

#endif
