#pragma once

#include "../math/math.h"
#include "body/body_state.h"
#include "../gait/gaits/tripod_config.h"

enum GaitTypes
{
    Tripod,
    Ripple
};

class AppState
{
public:
    // pub body : Body,

    // pub state : BodyState,
    // pub next_state : Option<BodyState>,
    BodyState state;
    BodyState next_state;

    // pub active_gait : GaitTypes,
    GaitTypes active_gait;
    // pub speed : OrderedFloat<f32>,
    float speed;
    // pub destination : OrderedVec3,
    Vec3 destination;
    // pub controller_direction : OrderedVec3, // normalised unit vector
    Vec3 controller_destination;

    // // configs
    // // TODO: modularise this
    // pub tripod_config : TripodConfig,
    TripodConfig tripod_config;

    // // debug
    // pub show_debug : bool,
};