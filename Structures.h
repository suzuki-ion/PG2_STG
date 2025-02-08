#pragma once

struct Vector2 final {
    Vector2 operator+(const Vector2 &v) const;
    Vector2 operator-(const Vector2 &v) const;
    Vector2 operator*(const Vector2 &v) const;
    Vector2 operator/(const Vector2 &v) const;
    Vector2 operator*(float f) const;
    Vector2 operator/(float f) const;
    Vector2 operator+=(const Vector2 &v);
    Vector2 operator-=(const Vector2 &v);
    Vector2 operator*=(const Vector2 &v);
    Vector2 operator/=(const Vector2 &v);

    float x = 0.0f;
    float y = 0.0f;
};