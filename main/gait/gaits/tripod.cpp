#include "../../math/math.h"
#include "../../state/appstate.h"

// fn leg_index_mapping(leg_type : &LegTypes) -> i32
// {
//     match leg_type
//     {
//         LegTypes::LF | LegTypes::LB | LegTypes::RM = > -1,
//                                       _ = > 1,
//     }
// }

int leg_index_mapping(LegTypes leg_type)
{
    switch (leg_type)
    {
    case LF:
    case LB:
    case RM:
        return -1;
        break;
    default:
        return 1;
    }
};

// fn orientation_correction(leg_type : &LegTypes) -> f32
// {
//     match leg_type
//     {
//         LegTypes::RF | LegTypes::RM | LegTypes::RB = > 1.0,
//                                       _ = > -1.0,
//     }
// }
float orientation_correction(LegTypes leg_type)
{
    switch (leg_type)
    {
    case RF:
    case RM:
    case RB:
        return 1.0;
        break;
    default:
        return -1.0;
    }
};

// // should the target be local to the leg or to the body?
// // orientation is either 1 or -1
// fn stride_length(target : Vec2, orientation : f32) -> f32
float stride_length(Vec2 target, float orientation)
{
    // let forward_relative = Vec2::new (target.y, target.x);
    Vec2 forward_relative = Vec2(target.y, target.x);

    float theta_s = (forward_relative.length_squared() > 1e-6) ? forward_relative.to_angle() : 0.0f;

    // let theta_s = if forward_relative.length_squared() > 1e-6
    // {
    //     forward_relative.to_angle()
    // }
    // else {
    //     0.0};

    // // println!("THETA_S: {theta_s}");

    // // right, orientation = 1
    // // left, orientation = -1

    // // left
    // // -pi - -pi/2: -1
    // // -pi/2 - pi/2: linear 0 to 1
    // // pi/2 - pi: 1

    // // right
    // // -pi - -pi/2: 1
    // // -pi/2 - pi/2: linear 1 to 0
    // // pi/2 - pi: -1

    // if theta_s
    //     <= (PI * -0.5)
    if (theta_s <= (PI * -0.5f))
    {
        // 1.0 * orientation
        return 1.0 * orientation;
    }
    else if (theta_s >= (PI * 0.5f))
    {
        // else if theta_s
        //     >= (PI * 0.5)
        //         -1.0 * orientation
        return -1.0 * orientation;
    }
    else
    {
        //     -(orientation * theta_s) / PI + 0.5
        return (-(orientation * theta_s) / PI) + 0.5f;
    }
};

// fn construct(state : &mut AppState, time : u128, target : &Vec3) -> HashMap<LegTypes, Vec3>
float *construct(AppState state, long long time, Vec3 *target)
{
    // let t = time as f32 / 1000.0;
    float t = time / 1000.0f;
    // let speed = state.speed.0;
    float speed = state.speed;

    // let rest = Vec3::new (
    //     state.tripod_config.distance.0,
    //     -(*state.body.ground_offset),
    //     0.0, );

    Vec3 rest = Vec3(
        state.tripod_config.distance,
        -(state.)
    );

    // let mut m = HashMap::new ();

    // let r = state
    //             .body
    //             .legs_mapping
    //             .keys()
    //             .enumerate()
    //             .map(| (_, leg_type) | {
    //                 let phase = (leg_index_mapping(leg_type) as f32) * (std::f32::consts::PI / 2.0);

    //                 // "ian why is orientation_correction negative?"
    //                 // im gonna be real with you, i have no idea
    //                 // i tried multiplying the .cos with negative correction but it didnt work
    //                 // only the one for stride_length worked
    //                 let s = stride_length(target.xz(), -orientation_correction(leg_type));

    //                 m.insert(leg_type, s);

    //                 let target = Vec3::new (
    //                     // REST.x + RADIUS * (SPEED * t + phase).cos(),
    //                     // REST.x,
    //                     // REST.x + RADIUS * (SPEED * t + phase).sin(),
    //                     0.0 + rest.x,
    //                     (rest.y + (state.tripod_config.ellipse_height.0 * (speed * t + phase).sin()))
    //                         .max(-(*state.body.ground_offset)),
    //                     // rest.z + (s * ((speed * t + phase).cos())),
    //                     rest.z + (s * *state.tripod_config.ellipse_width * ((speed * t + phase).cos() * (orientation_correction(leg_type)))), );
    //                 (leg_type.clone(), target) // so glad it impls +
    //             })
    //             .collect();

    // // println!("{m:?}");

    // r
};