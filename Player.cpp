#include <Novice.h>
#include "SceneManager.h"
#include "Player.h"
#include "Bullet.h"

Player::Player() {
    input_ = GetInput::GetInstance();
    pos_ = { 0.0f, 0.0f };
    speed_ = { 8.0f, 8.0f };
    radius_ = 32.0f;
    for (int i = 0; i < 16; i++) {
        bullet_[i] = std::make_unique<Bullet>();
    }
}

void Player::Initialize() {
    pos_ = { 640.0f, 360.0f };
    for (int i = 0; i < 16; i++) {
        bullet_[i]->Initialize();
    }
}

void Player::Update() {
    UpdateMove();
    UpdateShot();
}

void Player::Draw() {
    Novice::DrawEllipse(
        static_cast<int>(pos_.x),
        static_cast<int>(pos_.y),
        static_cast<int>(radius_),
        static_cast<int>(radius_),
        0.0f,
        WHITE,
        kFillModeSolid
    );

    for (int i = 0; i < 16; i++) {
        bullet_[i]->Draw();
    }
}

void Player::UpdateMove() {
    if (input_->Keys({ DIK_W, DIK_UP })) {
        pos_.y -= speed_.y;
    }
    if (input_->Keys({ DIK_S, DIK_DOWN })) {
        pos_.y += speed_.y;
    }
    if (input_->Keys({ DIK_A, DIK_LEFT })) {
        pos_.x -= speed_.x;
    }
    if (input_->Keys({ DIK_D, DIK_RIGHT })) {
        pos_.x += speed_.x;
    }
}

void Player::UpdateShot() {
    if (input_->TriggerKeys(DIK_SPACE)) {
        for (int i = 0; i < 16; i++) {
            if (!bullet_[i]->IsShot()) {
                bullet_[i]->Shot(pos_);
                break;
            }
        }
    }

    for (int i = 0; i < 16; i++) {
        bullet_[i]->Update();
    }
}
