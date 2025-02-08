#pragma once
#include "Structures.h"

class Bullet {
public:
    Bullet();

    void Initialize();
    void Update();
    void Draw();
    void Shot(const Vector2 &pos);
    void Hit();
    
    Vector2 GetPos() const { return pos_; }
    float GetRadius() const { return radius_; }
    bool IsShot() const { return isShot_; }

private:
    Vector2 pos_;
    Vector2 speed_;
    float radius_;
    bool isShot_;
};

