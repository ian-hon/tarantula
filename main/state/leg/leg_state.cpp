#include "leg_state.h"
#include "../../math/math.h"
#include "../../inverse_kinematics/transform.h"
#include "../segment/segment.h"
#include "../segment/segment_state.h"

void LegState::update(Vec3 &target)
{
    ThreePair three_pair = construct_three_pair(
        segment_states[Coxa].distance,
        segment_states[Femur].distance,
        segment_states[Tibia].distance,
        target);

    segment_states[Coxa].angle = three_pair.coxa;
    segment_states[Femur].angle = three_pair.femur;
    segment_states[Tibia].angle = three_pair.tibia;
}