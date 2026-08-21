// use std::collections::BTreeMap;

// use ordered_float::OrderedFloat;

// use crate::state::{body::Body, leg::LegTypes, states::leg_state::LegState};

// #[derive(Debug, Clone, PartialEq, Eq, Hash, PartialOrd, Ord)]
// pub struct BodyState
// {
//     pub length : OrderedFloat<f32>,
//         pub width : OrderedFloat<f32>,
//         pub height : OrderedFloat<f32>,
//         pub legs_mapping : BTreeMap<LegTypes, LegState>,
//         pub ground_offset : OrderedFloat<f32>, // distance from ground
// }

#pragma once

#include "../leg/leg.h"
#include "../leg/leg_state.h"

class BodyState
{
    // pub length : OrderedFloat<f32>,
    // pub width : OrderedFloat<f32>,
    // pub height : OrderedFloat<f32>,
    // pub legs_mapping : BTreeMap<LegTypes, LegState>,
    // pub ground_offset : OrderedFloat<f32>, // distance from ground

public:
    BodyState(
        float length,
        float width,
        float height,
        LegState legs_mapping[LEG_COUNT],
        float ground_offset);

    float length;
    float width;
    float height;
    LegState legs_mapping[LEG_COUNT];
    float ground_offset;

    BodyState clone();
};

// impl From<Body> for BodyState
// {
//     fn from(value : Body) -> Self
//     {
//         Self
//         {
//         legs_mapping:
//             BTreeMap::from_iter(
//                 value.legs_mapping.into_iter().map(| (k, v) | (k, v.into())), ),
//                 length : value.length,
//                 width : value.width,
//                 height : value.height,
//                 ground_offset : value.ground_offset,
//         }
//     }
// }
