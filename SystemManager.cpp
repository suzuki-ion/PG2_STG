#include <Novice.h>
#include "SystemManager.h"
#include "SceneManager.h"
#include "Scene.h"
#include "GetInput.h"

void SystemManager::Initialize() {
    Novice::Initialize(kWindowTitle_, static_cast<int>(winWidth_), static_cast<int>(winHeight_));
    SceneManager::GetInstance()->AddScene(std::make_unique<Title>());
    SceneManager::GetInstance()->AddScene(std::make_unique<Game>());
    SceneManager::GetInstance()->AddScene(std::make_unique<GameOver>());
    SceneManager::GetInstance()->AddScene(std::make_unique<Clear>());
}

void SystemManager::Process() {
	while (Novice::ProcessMessage() == 0) {
		Novice::BeginFrame();
        GetInput::GetInstance()->UpdateKeys();
        SceneManager::GetInstance()->Update();
        SceneManager::GetInstance()->Draw();
		Novice::EndFrame();
		if (isGameClose_) {
			break;
		}
	}
    Novice::Finalize();
}
