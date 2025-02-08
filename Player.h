#pragma once
#include <memory>
#include "Structures.h"
#include "Bullet.h"

class Player {
public:
    Player();

    void Initialize();
    void Update();
    void Draw();

    Vector2 GetPos() const { return pos_; }
    float GetRadius() const { return radius_; }
    Bullet *GetBullet(int index) { return bullet_[index].get(); }

private:
    GetInput *input_;
    Vector2 pos_;
    Vector2 speed_;
    float radius_;
    std::unique_ptr<Bullet> bullet_[16];

    void UpdateMove();
    void UpdateShot();
};