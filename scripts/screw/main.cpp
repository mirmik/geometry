#include <maho/rga3/motor3.h>
#include <maho/rga3/projection3.h>
#include <nos/fprint.h>

int main()
{
    auto pnt = maho::rga::point3<double>{200, 0, 10, 2};

    auto R =
        maho::rga::motor3_from_rotation_dirang<double>({0, 0, 1}, M_PI / 2);
    auto Tx = maho::rga::motor3_from_translation_vector<double>({1., 0, 0.});
    auto Ty = maho::rga::motor3_from_translation_vector<double>({0, 1, 0.});
    auto Tz = maho::rga::motor3_from_translation_vector<double>({0., 0, 1.});
    // auto R2 = maho::rga::motor3_from_rotation_dirang<double>({0, 0, 1},
    // -M_PI);

    nos::fprintln("pnt = {}", pnt);
    nos::fprintln("R = {}", R);
    nos::fprintln("Tx = {}", Tx);
    nos::fprintln("Ty = {}", Ty);
    nos::fprintln("Tz = {}", Tz);
    // nos::fprintln("R2*T*R = {}", R2 * T * R);
    nos::fprintln("R*pnt = {}", maho::rga::transform(R, pnt));
    nos::fprintln("Tx*pnt = {}", maho::rga::transform(Tx, pnt));
    nos::fprintln("Ty*pnt = {}", maho::rga::transform(Ty, pnt));
    nos::fprintln("Tz*pnt = {}", maho::rga::transform(Tz, pnt));

    nos::fprintln("Tx*R = {}", Tx * R);
    nos::fprintln("Tx*R*pnt = {}", maho::rga::transform(Tx * R, pnt));
    nos::fprintln("Tx*R*pnt = {}",
                  maho::rga::transform(Tx, maho::rga::transform(R, pnt)));

    nos::fprintln("Tx*R = {}", Tx * R);
    nos::fprintln("screwline(Tx*R) = {}", (Tx * R).screw_line());
    nos::fprintln("screwline(Tx*Tz*R) = {}", (Tx * Tz * R).screw_line());

    auto s = (Tx * Tz * R).screw_line();
    nos::fprintln("project(Tx*Tz*R) = {}",
                  maho::rga::project_to_origin(s.line()));
}