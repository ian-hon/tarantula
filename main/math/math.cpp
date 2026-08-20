#include "math.h"

#include <cmath>

// vec3
Vec3::Vec3() {};
Vec3::Vec3(float x, float y, float z) : x(x), y(y), z(z) {}

float Vec3::length() { sqrtf(length_squared()); }
float Vec3::length_squared() { (x * x) + (y * y) + (z * z); }
Vec2 Vec3::xz() { Vec2(x, z); }

// vec2
Vec2::Vec2() {}
Vec2::Vec2(float x, float y) : x(x), y(y) {}

float Vec2::length() { sqrtf(length_squared()); }
float Vec2::length_squared() { (x * x) + (y * y); }
float Vec2::to_angle() { atan2(x, y); }

// from math.com
constexpr float PI = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679;

template <typename T>
constexpr const T &clamp(const T &v, const T &lo, const T &hi)
{
    return (v < lo) ? lo : ((hi < v) ? hi : v);
}
