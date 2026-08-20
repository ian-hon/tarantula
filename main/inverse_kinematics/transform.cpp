#include "transform.h"

#include <cmath>
#include <algorithm>

ThreePair construct_three_pair(float coxa_length, float femur_length, float tibia_length, Vec3 transform)
{
    // let theta_c = f32::atan2(-transform.z, transform.x);
    float theta_c = atan2f(-transform.z, transform.x);

    // let horizontal = (f32::sqrt((transform.x * transform.x) + (transform.z * transform.z)) - coxa_length).max(0.0);
    float horizontal = std::max((transform.xz().length() - coxa_length), 0.0f);

    // let localised = Vec2::new (horizontal, transform.y);
    Vec2 localised = Vec2(horizontal, transform.y);

    // let end_pair = construct_end_pair(femur_length, tibia_length, localised);
    EndPair end_pair = construct_end_pair(femur_length, tibia_length, localised);

    // (theta_c, end_pair.0, end_pair.1)
    ThreePair{theta_c, end_pair.femur, end_pair.tibia};
}

EndPair construct_end_pair(float femur_length, float tibia_length, Vec2 transform)
{
    // let d = transform.length();
    float d = transform.length();

    // let cos_theta_t = ((d * d) - (tibia_length * tibia_length) - (femur_length * femur_length)) / (-2.0 * tibia_length * femur_length);
    float cos_theta_t = ((d * d) - (tibia_length * tibia_length) - (femur_length * femur_length)) / (-2.0 * tibia_length * femur_length);

    // if (-1.0 > cos_theta_t)
    //     || (1.0 < cos_theta_t)
    //     {
    //         bevy::log::warn !(
    //             "invalid IK dest\td={d:.3} femur={femur_length:.3} tibia={tibia_length:.3} cos_theta_t={cos_theta_t:.3}");
    //     }

    if ((-1.0 > cos_theta_t) || (1.0 < cos_theta_t))
    {
        // do nothing
        // i wanna keep this no_std, so no logging here
    }

    // clamp or else itll panic
    // let theta_t = f32::acos(cos_theta_t.clamp(-1.0, 1.0)) - std::f32::consts::PI;
    float theta_t = acosf(clamp(cos_theta_t, -1.0f, 1.0f)) - PI;

    // let theta_f = f32::atan2(transform.y, transform.x) - f32::asin(((tibia_length * f32::sin(theta_t)) / d).clamp(-1.0, 1.0));
    float theta_f = atan2f(transform.y, transform.x) - asinf(clamp((tibia_length * sinf(theta_t)) / d, -1.0f, 1.0f));

    EndPair{theta_f, theta_t};
}
