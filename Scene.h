#pragma once
#include <memory>
#include "Structures.h"
#include "GetInput.h"
#include "Player.h"
#include "Enemy.h"

class SceneManager;

enum SceneType {
    TITLE,
    GAME,
    GAMEOVER,
    CLEAR
};

//--------- SCENE ---------//

class Scene {
protected:
    SceneManager *sceneManager_;
    GetInput *input_;
    SceneType sceneType_;
public:
    Scene();
    SceneType GetSceneType() const { return sceneType_; }
    virtual void Initialize() {};
    virtual void Update() {};
    virtual void Draw() {};
};

//--------- TITLE ---------//

class Title final : public Scene {
public:
    Title();
    void Update() override;
    void Draw() override;
};

//--------- GAME ---------//

class Game final : public Scene {
public:
    Game();
    void Initialize() override;
    void Update() override;
    void Draw() override;
private:
    std::unique_ptr<Player> player_;
    std::unique_ptr<Enemy> enemy_[16];
    int enemySpawnCount_;
    int enemyKillCount_;
    int enemtKillMax_;
    void UpdateEnemySpawn();
    void UpdateCollision();
    void UpdateCollisionPlayerToEnemy();
    void UpdateCollisionBulletToEnemy();
};

//--------- GAMEOVER ---------//

class GameOver final : public Scene {
public:
    GameOver();
    void Update() override;
    void Draw() override;
};

//--------- CLEAR ---------//

class Clear final : public Scene {
public:
    Clear();
    void Update() override;
    void Draw() override;
};