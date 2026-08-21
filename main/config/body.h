#include "leg.h"

class Body {
    float length;
    float width;
    float height;
    Leg *legs_mapping[LEG_COUNT];
    float ground_offset;
};