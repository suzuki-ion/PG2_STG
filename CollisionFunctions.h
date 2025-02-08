#pragma once
#include "Structures.h"

class IsHit {
public:
    static bool CircleToCircle(const Vector2 &pos1, float radius1, const Vector2 &pos2, float radius2);
    static bool CircleToCapsule(const Vector2 &circlePos, float circleRadius, const Vector2 &capsulePos1, const Vector2 &capsulePos2, float capsuleRadius);
};

