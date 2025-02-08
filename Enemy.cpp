#include <Novice.h>
#include "Enemy.h"

Enemy::Enemy() {
    pos_ = { 0.0f, 0.0f };
    speed_ = { 0.0f, 8.0f };
    radius_ = 32.0f;
    isAlive_ = false;
}

void Enemy::Initialize() {
    pos_ = { 0.0f, 0.0f };
    isAlive_ = false;
}

void Enemy::Update() {
    if (!isAlive_) {
        return;
    }
    pos_ += speed_;
    if (pos_.y > 720.0f) {
        isAlive_ = false;
    }
}

void Enemy::Draw() {
    if (!isAlive_) {
        return;
    }
    Novice::DrawEllipse(
        static_cast<int>(pos_.x),
        static_cast<int>(pos_.y),
        static_cast<int>(radius_),
        static_cast<int>(radius_),
        0.0f,
        BLUE,
        kFillModeSolid
    );
}

void Enemy::Spawn(const Vector2 &pos) {
    if (isAlive_) {
        return;
    }
    pos_ = pos;
    isAlive_ = true;
}

void Enemy::Hit() {
    isAlive_ = false;
}