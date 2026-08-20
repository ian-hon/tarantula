// use std::{collections::HashMap, f32::consts::PI};

// use bevy::math::{Vec2, Vec3, Vec3Swizzles};
// use ordered_float::OrderedFloat;

// use crate::{
//     gait::gait::{Gait, GaitConfig, SliderDescriptor},
//     state::{app_state::AppState, leg::LegTypes},
// };

// pub struct Tripod;

// #[derive(Debug, Clone, PartialEq, Eq, Hash)]
// pub struct TripodConfig
// {
//     pub distance : OrderedFloat<f32>, // whats the max tho

//         pub ellipse_height : OrderedFloat<f32>,
//         pub ellipse_width : OrderedFloat<f32>,
// }

#include "../gait.h"

class Tripod : public Gait
{
public:
    static float *construct(AppState *state, long long time, Vec3 target)
    {
        return nullptr;
    }
};

// impl Default for TripodConfig
// {
//     fn default()->Self
//     {
//         Self
//         {
//         distance:
//             OrderedFloat(3.3),
//                 ellipse_height : OrderedFloat(0.8),
//                                  ellipse_width : OrderedFloat(1.0),
//         }
//     }
// }

// impl GaitConfig for TripodConfig
// {
//     fn sliders(&self)->Vec<SliderDescriptor>
//     {
//         vec![
//             SliderDescriptor {
//                 label: "distance",
//                 min: 0.0,
//                 max: 10.0, // if its too high it crashes lmao
//                 initial: self.distance.0,
//                 setter: |state, v| {
//                     println!("distance changed: {v:?}");
//                     state.tripod_config.distance = OrderedFloat(v)
//     }
//     ,
// }
// ,
// SliderDescriptor{
//     label : "ellipse height",
//     min : 0.0,
//     max : 5.0,
//     initial : self.ellipse_height.0,
//     setter : | state,
//     v | {
//             println !("ellipse height changed: {v:?}");
// state.tripod_config.ellipse_height = OrderedFloat(v)
// }
// ,
// }
// ,
// SliderDescriptor{
//     label : "ellipse width",
//     min : 0.0,
//     max : 2.0,
//     initial : self.ellipse_width.0,
//     setter : | state,
//     v | {
//             println !("ellipse width changed: {v:?}");
// state.tripod_config.ellipse_width = OrderedFloat(v)
// }
// ,
// },
//         ]
// }
// }

// fn leg_index_mapping(leg_type : &LegTypes) -> i32
// {
//     match leg_type
//     {
//         LegTypes::LF | LegTypes::LB | LegTypes::RM = > -1,
//                                       _ = > 1,
//     }
// }

// fn orientation_correction(leg_type : &LegTypes) -> f32
// {
//     match leg_type
//     {
//         LegTypes::RF | LegTypes::RM | LegTypes::RB = > 1.0,
//                                       _ = > -1.0,
//     }
// }

// // should the target be local to the leg or to the body?
// // orientation is either 1 or -1
// fn stride_length(target : Vec2, orientation : f32) -> f32
// {
//     let forward_relative = Vec2::new (target.y, target.x);
//     let theta_s = if forward_relative.length_squared() > 1e-6
//     {
//         forward_relative.to_angle()
//     }
//     else {
//         0.0};

//     // println!("THETA_S: {theta_s}");

//     // right, orientation = 1
//     // left, orientation = -1

//     // left
//     // -pi - -pi/2: -1
//     // -pi/2 - pi/2: linear 0 to 1
//     // pi/2 - pi: 1

//     // right
//     // -pi - -pi/2: 1
//     // -pi/2 - pi/2: linear 1 to 0
//     // pi/2 - pi: -1

//     if theta_s
//         <= (PI * -0.5)
//         {
//             1.0 * orientation
//         }
//     else if theta_s
//         >= (PI * 0.5)
//         {
//             -1.0 * orientation
//         }
//     else
//     {
//         -(orientation * theta_s) / PI + 0.5
//     }
// }

// impl Gait for Tripod
// {
//     fn construct(state : &mut AppState, time : u128, target : &Vec3) -> HashMap<LegTypes, Vec3>
//     {
//         let t = time as f32 / 1000.0;
//         let speed = state.speed.0;

//         let rest = Vec3::new (
//             state.tripod_config.distance.0,
//             -(*state.body.ground_offset),
//             0.0, );

//         let mut m = HashMap::new ();

//         let r = state
//                     .body
//                     .legs_mapping
//                     .keys()
//                     .enumerate()
//                     .map(| (_, leg_type) | {
//                         let phase = (leg_index_mapping(leg_type) as f32) * (std::f32::consts::PI / 2.0);

//                         // "ian why is orientation_correction negative?"
//                         // im gonna be real with you, i have no idea
//                         // i tried multiplying the .cos with negative correction but it didnt work
//                         // only the one for stride_length worked
//                         let s = stride_length(target.xz(), -orientation_correction(leg_type));

//                         m.insert(leg_type, s);

//                         let target = Vec3::new (
//                             // REST.x + RADIUS * (SPEED * t + phase).cos(),
//                             // REST.x,
//                             // REST.x + RADIUS * (SPEED * t + phase).sin(),
//                             0.0 + rest.x,
//                             (rest.y + (state.tripod_config.ellipse_height.0 * (speed * t + phase).sin()))
//                                 .max(-(*state.body.ground_offset)),
//                             // rest.z + (s * ((speed * t + phase).cos())),
//                             rest.z + (s * *state.tripod_config.ellipse_width * ((speed * t + phase).cos() * (orientation_correction(leg_type)))), );
//                         (leg_type.clone(), target) // so glad it impls +
//                     })
//                     .collect();

//         // println!("{m:?}");

//         r
//     }
// }
