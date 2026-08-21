#pragma once

#include "../../math/math.h"
#include "../segment/segment.h"
#include "../segment/segment_state.h"

class LegState
{
public:
    SegmentState segment_states[SEGMENT_COUNT];
    Vec3 target;

    void update(Vec3 &target);
};