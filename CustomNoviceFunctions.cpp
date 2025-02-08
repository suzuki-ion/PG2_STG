#pragma once
#include <Novice.h>

void DrawBoxForFloat(float x, float y, float w, float h, unsigned int color = WHITE, float angle = 0.0f, FillMode fillMode = kFillModeSolid) {
	Novice::DrawBox(
		static_cast<int>(x),
		static_cast<int>(y),
		static_cast<int>(w),
		static_cast<int>(h),
		angle, color, fillMode
	);
}

void DrawTriangleForFloat(float x1, float y1, float x2, float y2, float x3, float y3, unsigned int color = WHITE, FillMode fillMode = kFillModeSolid) {
	Novice::DrawTriangle (
		static_cast<int>(x1),
		static_cast<int>(y1),
		static_cast<int>(x2),
		static_cast<int>(y2),
		static_cast<int>(x3),
		static_cast<int>(y3),
		color, fillMode
	);
}

void DrawLineForFloat(float x1, float y1, float x2, float y2, unsigned int color = WHITE) {
	Novice::DrawLine(
		static_cast<int>(x1),
		static_cast<int>(y1),
		static_cast<int>(x2),
		static_cast<int>(y2),
		color
	);
}

void DrawEllipseForFloat(float x, float y, float radiusX, float radiusY, unsigned int color = WHITE, float angle = 0.0f, FillMode fillMode = kFillModeSolid) {
	Novice::DrawEllipse(
		static_cast<int>(x),
		static_cast<int>(y),
		static_cast<int>(radiusX),
		static_cast<int>(radiusY),
		angle, color, fillMode
	);
}

void DrawSpriteForFloat(float x, float y, int textureHandle, unsigned int color = WHITE, float scaleX = 1.0f, float scaleY = 1.0f, float angle = 0.0f) {
	Novice::DrawSprite(
		static_cast<int>(x),
		static_cast<int>(y),
		textureHandle, scaleX, scaleY, angle, color
	);
}

void DrawSpriteRectForFloat(float destX, float destY, float srcX, float srcY, float srcW, float srcH, int textureHandle, unsigned int color = WHITE, float scaleX = 1.0f, float scaleY = 1.0f, float angle = 0.0f) {
	Novice::DrawSpriteRect(
		static_cast<int>(destX),
		static_cast<int>(destY),
		static_cast<int>(srcX),
		static_cast<int>(srcY),
		static_cast<int>(srcW),
		static_cast<int>(srcH),
		textureHandle, scaleX, scaleY, angle, color
	);
}

void DrawQuadForFloat(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, float srcX, float srcY, float srcW, float srcH, int textureHandle, unsigned int color = WHITE) {
	Novice::DrawQuad(
		static_cast<int>(x1),
		static_cast<int>(y1),
		static_cast<int>(x2),
		static_cast<int>(y2),
		static_cast<int>(x3),
		static_cast<int>(y3),
		static_cast<int>(x4),
		static_cast<int>(y4),
		static_cast<int>(srcX),
		static_cast<int>(srcY),
		static_cast<int>(srcW),
		static_cast<int>(srcH),
		textureHandle, color
	);
}