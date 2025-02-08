#pragma once
#include <vector>
#include <memory>
#include "Structures.h"
#include "Scene.h"

class SceneManager final {
private:
    SceneManager() = default;
    ~SceneManager() = default;
    std::vector<std::unique_ptr<Scene>> scenes_;
    int activeSceneIndex_ = 0;

public:
    SceneManager(const SceneManager &) = delete;
    SceneManager &operator=(const SceneManager &) = delete;
    SceneManager(SceneManager &&) = delete;
    SceneManager &operator=(SceneManager &&) = delete;

    static SceneManager *GetInstance() {
        static SceneManager instance;
        return &instance;
    }

    void AddScene(std::unique_ptr<Scene> scene);
    void PopScene();
    void SetActiveScene(SceneType sceneType);
    void Destroy();

    void Update();
    void Draw();
};