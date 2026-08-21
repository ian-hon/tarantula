#pragma once

// cpp doesnt have appropriate hashtables, so just index
constexpr int LEG_COUNT = 6;

enum LegTypes
{
    RF = 0,
    RM = 1,
    RB = 2,
    LF = 3,
    LM = 4,
    LB = 5,
};
