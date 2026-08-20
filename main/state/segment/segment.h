#include "../../math/math.h"

constexpr int SEGMENT_COUNT = 3;
enum SegmentTypes
{
    Coxa,
    Femur,
    Tibia,
};

class Segment
{
    Vec3 end_transform;
    Vec3 axis;
};
