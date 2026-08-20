#pragma once

#include "../math/math.h"

struct ThreePair
{
    float coxa;
    float femur;
    float tibia;
};

struct EndPair
{
    float femur;
    float tibia;
};

ThreePair construct_three_pair(float coxa_length, float femur_length, float tibia_length, Vec3 transform);
EndPair construct_end_pair(float femur_length, float tibia_length, Vec2 transform);
