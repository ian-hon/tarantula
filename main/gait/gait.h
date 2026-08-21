// use std::collections::HashMap;

// use bevy::{math::Vec3, prelude::*};

// use crate::{
//     gait::gaits::tripod::Tripod,
//     state::{app_state::AppState, leg::LegTypes},
// };

// #[derive(Debug, Clone, PartialEq, Eq, Hash)]
// pub enum GaitTypes {
//     Tripod,
//     Ripple,
// }

#pragma once

#include "../state/appstate.h"
#include "../math/math.h"

class Gait
{
public:
    static Vec3 *construct(AppState *state, long long time, Vec3 &target);
};

void progress_gait(AppState state, long long time);

// pub trait Gait {
//     fn construct(state: &mut AppState, time: u128, target: &Vec3) -> HashMap<LegTypes, Vec3>;
// }

// pub fn progress_gait(mut state: ResMut<AppState>, time: Res<Time>) {
//     let target: Vec3 = state.destination.into();

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
// }
