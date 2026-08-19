#include "transform.h"

#include <cmath>

ThreePair construct_three_pair(float coxa, float femur, float tibia)
{
    let theta_c = f32::atan2(-transform.z, transform.x);

    float theta_c = atan2f()

    let horizontal = (f32::sqrt((transform.x * transform.x) + (transform.z * transform.z)) - coxa_length)
                         .max(0.0);

    let localised = Vec2::new (horizontal, transform.y);

    let end_pair = construct_end_pair(femur_length, tibia_length, localised);

    (theta_c, end_pair.0, end_pair.1)
}

EndPair construct_end_pair(float femur, float tibia)
{
    let d = transform.length();

    let cos_theta_t = ((d * d) - (tibia_length * tibia_length) - (femur_length * femur_length)) / (-2.0 * tibia_length * femur_length);

    if (-1.0 > cos_theta_t)
        || (1.0 < cos_theta_t)
        {
            bevy::log::warn !(
                "invalid IK dest\td={d:.3} femur={femur_length:.3} tibia={tibia_length:.3} cos_theta_t={cos_theta_t:.3}");
        }

    // clamp or else itll panic
    let theta_t = f32::acos(cos_theta_t.clamp(-1.0, 1.0)) - std::f32::consts::PI;

    let theta_f = f32::atan2(transform.y, transform.x) - f32::asin(((tibia_length * f32::sin(theta_t)) / d).clamp(-1.0, 1.0));

    (theta_f, theta_t)
}
