struct Vec3
{
    float x;
    float y;
    float z;

    Vec3();
    Vec3(float x, float y, float z);

    float length();
    float length_squared();

    Vec2 xz();
};

struct Vec2
{
    float x;
    float y;

    Vec2();
    Vec2(float x, float y);

    float length();
    float length_squared();

    float to_angle();
};

constexpr float PI;

template <typename T>
constexpr const T &clamp(const T &v, const T &lo, const T &hi);