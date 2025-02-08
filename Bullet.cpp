#include <Novice.h>
#include "Bullet.h"

Bullet::Bullet() {
    pos_ = { 0.0f, 0.0f };
    speed_ = { 0.0f, -32.0f };
    radius_ = 8.0f;
    isShot_ = false;
}

void Bullet::Initialize() {
    pos_ = { 0.0f, 0.0f };
    isShot_ = false;
}

void Bullet::Shot(const Vector2 &pos) {
    if (isShot_) {
        return;
    }
    pos_ = pos;
    isShot_ = true;
}

void Bullet::Hit() {
    isShot_ = false;
}

void Bullet::Update() {
    if (!isShot_) {
        return;
    }

    pos_ += speed_;
    if (pos_.y < 0.0f) {
        isShot_ = false;
    }
}

void Bullet::Draw() {
    if (!isShot_) {
        return;
    }
    Novice::DrawEllipse(
        static_cast<int>(pos_.x),
        static_cast<int>(pos_.y),
        static_cast<int>(radius_),
        static_cast<int>(radius_),
        0.0f,
        RED,
        kFillModeSolid
    );
}