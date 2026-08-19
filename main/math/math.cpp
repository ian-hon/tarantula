#include "math.h"

#include <cmath>

// vec3
Vec3::Vec3() {};
Vec3::Vec3(float x, float y, float z)
    : x(x), y(y), z(z) {}

float Vec3::length() { return sqrtf(length_squared()); }
float Vec3::length_squared()
{
    return (x * x) + (y * y) + (z * z);
}

// vec2
Vec2::Vec2() {}
Vec2::Vec2(float x, float y)
    : x(x), y(y) {}

float Vec2::length() { return sqrtf(length_squared()); }
float Vec2::length_squared() { return (x * x) + (y * y); }

float Vec2::to_angle()
{
    return atan2(x, y);
}
