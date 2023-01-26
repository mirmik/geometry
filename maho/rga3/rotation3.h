#ifndef MAHO_RGA3_ROTATION3_H
#define MAHO_RGA3_ROTATION3_H

#include <maho/rga3/quat.h>

namespace maho
{
    namespace rga
    {
        class rotation3
        {
            quat _v;

        public:
            rotation3() : _v(0, 0, 0, 1) {}
            rotation3(const quat &v) : _v(v) {}
            rotation3(const rotation3 &r) : _v(r._v) {}
            rotation3 &operator=(const rotation3 &r)
            {
                _v = r._v;
                return *this;
            }

            constexpr quat v() const { return _v; }
            constexpr quat &v() { return _v; }
        };
    }
}

#endif // MAHO_RGA3_ROTATION3_H