#pragma once

class SystemManager {
private:
    SystemManager() = default;
    ~SystemManager() = default;
    
    const char *kWindowTitle_ = "LC1A_12_スズキ_イオン";
    float winWidth_ = 1280.0f;
    float winHeight_ = 720.0f;

    bool isGameClose_ = false;

public:
    SystemManager(const SystemManager &) = delete;
    SystemManager &operator=(const SystemManager &) = delete;
    SystemManager(SystemManager &&) = delete;
    SystemManager &operator=(SystemManager &&) = delete;

    static SystemManager *GetInstance() {
        static SystemManager instance;
        return &instance;
    }

    void Initialize();
    void Process();

    void CloseGame() { isGameClose_ = true; }
    bool IsGameClose() const { return isGameClose_; }

    const char *GetWindowTitle() const { return kWindowTitle_; }
    float GetWinWidth() const { return winWidth_; }
    float GetWinHeight() const { return winHeight_; }
};

