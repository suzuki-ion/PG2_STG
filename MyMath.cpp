#include <assert.h>
#include <math.h>
#include "MyMath.h"
#include "stdlib.h"

int RandRange(int min, int max) {
    return rand() % (max + 1 - min) + min;
}

float Length(const Vector2 &vector) {
    return sqrtf(vector.x * vector.x + vector.y * vector.y);
}

Vector2 Normalize(const Vector2 &vector) {
    float length = Length(vector);
    if (length != 0.0f) {
        return {
            vector.x / length,
            vector.y / length
        };
    } else {
        return { 0.0f, 0.0f };
    }
}

float DotProduct(const Vector2 &vec1, const Vector2 &vec2) {
    return vec1.x * vec2.x + vec1.y * vec2.y;
}

float Clamp(float t, float min, float max) {
    if (t > max) {
        return max;
    } else if (t < min) {
        return min;
    }
    return t;
}