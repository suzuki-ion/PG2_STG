#include "CollisionFunctions.h"
#include "MyMath.h"

bool IsHit::CircleToCircle(const Vector2 &pos1, float radius1, const Vector2 &pos2, float radius2) {
    float distance = Length(pos2 - pos1);
    if (distance < radius1 + radius2) {
        return true;
    } else {
        return false;
    }
}

bool IsHit::CircleToCapsule(const Vector2 &circlePos, float circleRadius, const Vector2 &capsulePos1, const Vector2 &capsulePos2, float capsuleRadius) {
    Vector2 d = circlePos - capsulePos1;
    Vector2 ba = capsulePos2 - capsulePos1;
    Vector2 e = Normalize(ba);
    float t = DotProduct(d, e) / Length(ba);
    t = Clamp(t, 0.0f, 1.0f);
    Vector2 f = (capsulePos1 * (1.0f - t)) + (capsulePos2 * t);
    float distance = Length(circlePos - f);
    if (distance < circleRadius + capsuleRadius) {
        return true;
    } else {
        return false;
    }
}
