#include "../math/math.h"

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

    // // debug
    // pub show_debug : bool,
};