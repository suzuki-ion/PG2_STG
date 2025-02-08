#include <windows.h>
#include "Structures.h"

void ScreenSizeGet(int* width, int* height) {
	*width = GetSystemMetrics(SM_CXSCREEN);
	*height = GetSystemMetrics(SM_CYSCREEN);
}

Vector2Int GetGameWindowSize(const int &gameWidth, const int &gameHeight, const int &monitorWidth, const int &monitorHeight) {
	// 求めたウィンドウのサイズを保存する変数
	Vector2Int windowSize = {
		gameWidth,
		gameHeight
	};

	// ゲーム画面の大きさとモニターの解像度の大きさが何倍差か求める
	float scaleX = static_cast<float>(gameWidth) / static_cast<float>(monitorWidth);
	float scaleY = static_cast<float>(gameHeight) / static_cast<float>(monitorHeight);

	// 縦と横どっちが倍率高いかを比較して小さいほうを大きいほうと同じ倍率にして返す
	if (scaleX > scaleY) {
		windowSize.y = static_cast<int>(static_cast<float>(monitorHeight) * scaleX);
	} else if (scaleY > scaleX) {
		windowSize.x = static_cast<int>(static_cast<float>(monitorWidth) * scaleY);
	}

	return windowSize;
}
