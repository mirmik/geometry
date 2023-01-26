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

    template <class T> using mat33 = linalg::mat<T, 3, 3>;

    template <class T> using mat44 = linalg::mat<T, 4, 4>;
}

#endif
