#include "Structures.h"

Vector2 Vector2::operator+(const Vector2 &v) const {
    return { x + v.x, y + v.y };
}

Vector2 Vector2::operator-(const Vector2 &v) const {
    return { x - v.x, y - v.y };
}

Vector2 Vector2::operator*(const Vector2 &v) const {
    return { x * v.x, y * v.y };
}

Vector2 Vector2::operator/(const Vector2 &v) const {
    return { x / v.x, y / v.y };
}

Vector2 Vector2::operator*(float f) const {
    return { x * f, y * f };
}

Vector2 Vector2::operator/(float f) const {
    return { x / f, y / f };
}

Vector2 Vector2::operator+=(const Vector2 &v) {
    return { x += v.x, y += v.y };
}

Vector2 Vector2::operator-=(const Vector2 &v) {
    return { x -= v.x, y -= v.y };
}

Vector2 Vector2::operator*=(const Vector2 &v) {
    return { x *= v.x, y *= v.y };
}

Vector2 Vector2::operator/=(const Vector2 &v) {
    return { x /= v.x, y /= v.y };
}