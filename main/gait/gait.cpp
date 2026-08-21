#include "../state/appstate.h"

#include "gaits/tripod.h"
#include "leg/leg.h"

// pub fn progress_gait(mut state: ResMut<AppState>, time: Res<Time>) {
void progress_gait(AppState state, long long time)
{
    //     let target: Vec3 = state.destination.into();
    Vec3 *targets = nullptr;
    switch (state.active_gait)
    {
    case Tripod:
        targets = Tripod::construct(&state, time, state.destination);
        break;
    case Ripple:
        break;
    default:
        break;
    }

    BodyState next_body_state = state.state.clone();
    if (targets)
    {
        for (int i = 0; i < LEG_COUNT; i++)
        {
            next_body_state.legs_mapping[i].update(targets[i]);
        }
    }
    state.next_state = next_body_state;

    //     let targets = match state.active_gait {
    //         GaitTypes::Tripod => Tripod::construct(&mut state, time.elapsed().as_millis(), &target),
    //         GaitTypes::Ripple => return,
    //     };

    //     let mut next_body_state = state.state.clone();
    //     for (leg_type, coxa_target) in targets {
    //         let Some(leg_state) = next_body_state.legs_mapping.get_mut(&leg_type) else {
    //             continue;
    //         };
    //         leg_state.update(coxa_target);
    //     }

    //     state.next_state = Some(next_body_state);
};
