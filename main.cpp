#include <Novice.h>
#include "SystemManager.h"
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    SystemManager *systemManager = SystemManager::GetInstance();
    systemManager->Initialize();
    systemManager->Process();
	return 0;
}