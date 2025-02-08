#include <Novice.h>
#include "SystemManager.h"
#include "SceneManager.h"
#include "Scene.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "CollisionFunctions.h"
#include "MyMath.h"

Scene::Scene() {
    sceneManager_ = SceneManager::GetInstance();
    input_ = GetInput::GetInstance();
    sceneType_ = TITLE;
}

//--------- TITLE ---------//

Title::Title() {
    sceneType_ = TITLE;
}

void Title::Update() {
    if (input_->TriggerKeys(DIK_SPACE)) {
        sceneManager_->SetActiveScene(GAME);
    } else if (input_->TriggerKeys(DIK_ESCAPE)) {
        SystemManager::GetInstance()->CloseGame();
    }
}

void Title::Draw() {
    Novice::ScreenPrintf(640, 360, "Push space to game start.");
}

//--------- GAME ---------//

Game::Game() {
    sceneType_ = GAME;
    enemySpawnCount_ = 0;
    enemyKillCount_ = 0;
    enemtKillMax_ = 16;
    player_ = std::make_unique<Player>();
    for (int i = 0; i < 16; i++) {
        enemy_[i] = std::make_unique<Enemy>();
    }
}

void Game::Initialize() {
    enemySpawnCount_ = 0;
    enemyKillCount_ = 0;
    player_->Initialize();
    for (int i = 0; i < 16; i++) {
        enemy_[i]->Initialize();
    }
}

void Game::Update() {
    UpdateEnemySpawn();
    player_->Update();
    for (int i = 0; i < 16; i++) {
        enemy_[i]->Update();
    }
    UpdateCollision();

    if (enemyKillCount_ >= enemtKillMax_) {
        sceneManager_->SetActiveScene(CLEAR);
    }

    if (input_->TriggerKeys(DIK_ESCAPE)) {
        sceneManager_->SetActiveScene(TITLE);
    }
}

void Game::Draw() {
    player_->Draw();
    for (int i = 0; i < 16; i++) {
        enemy_[i]->Draw();
    }

    Novice::ScreenPrintf(16, 16, "Kill: %d / %d", enemyKillCount_, enemtKillMax_);
}

void Game::UpdateEnemySpawn() {
    static Vector2 spawnPos;
    if (enemySpawnCount_ > 0) {
        enemySpawnCount_--;
        return;
    }
    
    spawnPos = {
        static_cast<float>(RandRange(0, 1280)),
        -128.0f
    };
    for (int i = 0; i < 16; i++) {
        if (enemy_[i]->IsAlive()) {
            continue;
        }
        enemy_[i]->Spawn(spawnPos);
        enemySpawnCount_ = 30;
        break;
    }
}

void Game::UpdateCollision() {
    UpdateCollisionPlayerToEnemy();
    UpdateCollisionBulletToEnemy();
}

void Game::UpdateCollisionPlayerToEnemy() {
    for (int i = 0; i < 16; i++) {
        if (!enemy_[i]->IsAlive()) {
            continue;
        }
        if (IsHit::CircleToCircle(player_->GetPos(), player_->GetRadius(), enemy_[i]->GetPos(), enemy_[i]->GetRadius())) {
            sceneManager_->SetActiveScene(GAMEOVER);
        }
    }
}

void Game::UpdateCollisionBulletToEnemy() {
    static Bullet *bullet;

    for (int i = 0; i < 16; i++) {
        if (!player_->GetBullet(i)->IsShot()) {
            continue;
        }
        bullet = player_->GetBullet(i);
        for (int j = 0; j < 16; j++) {
            if (!enemy_[j]->IsAlive()) {
                continue;
            }
            if (IsHit::CircleToCircle(player_->GetBullet(i)->GetPos(), player_->GetBullet(i)->GetRadius(), enemy_[j]->GetPos(), enemy_[j]->GetRadius())) {
                player_->GetBullet(i)->Hit();
                enemy_[j]->Hit();
                enemyKillCount_++;
            }
        }
    }
}

//--------- GAMEOVER ---------//

GameOver::GameOver() {
    sceneType_ = GAMEOVER;
}

void GameOver::Update() {
    if (input_->TriggerKeys({ DIK_SPACE, DIK_ESCAPE })) {
        sceneManager_->SetActiveScene(TITLE);
    }
}

void GameOver::Draw() {
    Novice::ScreenPrintf(640, 360, "Game Over. Push space to title.");
}

//--------- CLEAR ---------//

Clear::Clear() {
    sceneType_ = CLEAR;
}

void Clear::Update() {
    if (input_->TriggerKeys({ DIK_SPACE, DIK_ESCAPE })) {
        sceneManager_->SetActiveScene(TITLE);
    }
}

void Clear::Draw() {
    Novice::ScreenPrintf(640, 360, "Game Clear. Push space to title.");
}
