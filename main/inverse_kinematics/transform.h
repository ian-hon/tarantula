struct ThreePair
{
    float coxa;
    float femur;
    float tibia;
};

struct EndPair
{
    float femur;
    float tibia;
};

ThreePair construct_three_pair(float coxa, float femur, float tibia, Vec3 target);
EndPair construct_end_pair();
