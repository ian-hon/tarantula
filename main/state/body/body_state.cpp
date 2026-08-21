#include "body_state.h"

BodyState::BodyState(
    float length,
    float width,
    float height,
    LegState *_legs_mapping,
    float ground_offset) : length(length),
                           width(width),
                           height(height),
                           ground_offset(ground_offset)

{
    for (int i = 0; i < LEG_COUNT; i++)
    {
        legs_mapping[i] = _legs_mapping[i];
    }
}

BodyState BodyState::clone()
{
    return BodyState(
        length,
        width,
        height,
        legs_mapping, // is this ok? or need &legs_mapping?
        ground_offset);
}