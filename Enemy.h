#pragma once
#include "Structures.h"

class Enemy {
public:
    Enemy();

    void Initialize();
    void Update();
    void Draw();
    void Spawn(const Vector2 &pos);
    void Hit();

    Vector2 GetPos() const { return pos_; }
    float GetRadius() const { return radius_; }
    bool IsAlive() const { return isAlive_; }

private:
    Vector2 pos_;
    Vector2 speed_;
    float radius_;
    bool isAlive_;
};

