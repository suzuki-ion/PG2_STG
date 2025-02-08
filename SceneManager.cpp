#include "SceneManager.h"

void SceneManager::AddScene(std::unique_ptr<Scene> scene) {
    scenes_.push_back(std::move(scene));
}

void SceneManager::PopScene() {
    scenes_.pop_back();
}

void SceneManager::SetActiveScene(SceneType sceneType) {
    for (int i = 0; i < scenes_.size(); i++) {
        if (scenes_[i]->GetSceneType() == sceneType) {
            activeSceneIndex_ = i;
            scenes_[activeSceneIndex_]->Initialize();
            break;
        }
    }
}

void SceneManager::Destroy() {
    scenes_.clear();
}

void SceneManager::Update() {
    scenes_[activeSceneIndex_]->Update();
}

void SceneManager::Draw() {
    scenes_[activeSceneIndex_]->Draw();
}