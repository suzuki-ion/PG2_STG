#include <stdlib.h>
#include <math.h>
#include "CommonFunctions.h"
#define M_PI (4.0f * atanf(1.0f))

template <typename Type>
void Swap(Type *a, Type *b) {
	Type tmp = *a;
	*a = *b;
	*b = tmp;
}

void Shuffle(int(*array)[], int max) {
	for (int i = 0; i < max; i++) {
		// i番目の値とランダムな位置の値を交換する
		Swap(&(*array)[i], &(*array)[rand() % max]);
	}
}

int CustomRangeRand(int min, int max) {
	return rand() % (max + 1 - min) + min;
}

float ConvertDeg2Rad(float degree) {
	return degree * M_PI / 180.0f;
}

float ConvertRad2Deg(float radian) {
	return radian * 180.0f / M_PI;
}

float Length(float x, float y) {
	return sqrtf(x * x + y * y);
}

Vector2 Normalize(float x, float y) {
	float length = Length(x, y);

	// length が 0 でなければ正規化した長さを返す
	if (length != 0.0f) {
		return {
			x / length,
			y / length
		};
	} else {
		// length が 0 なら 0 を返す
		return { 0.0f, 0.0f };
	}
}

float DotProduct(float x1, float y1, float x2, float y2) {
	return x1 * x2 + y1 * y2;
}

float CrossProduct(float x1, float y1, float x2, float y2) {
	return x1 * y2 - y1 * x2;
}

float Clamp(float t, float min, float max) {
	// tが指定された値を超えてたら指定された値で初期化
	if (t > max) {
		t = max;
	} else if (t < min) {
		t = min;
	}
	return t;
}

int IsCircle2CircleHit(float x1, float y1, float radius1, float x2, float y2, float radius2) {
	float x = x2 - x1;
	float y = y2 - y1;

	// 2つの円の半径の和よりも中心点間の距離のほうが短いならtrueを返す
	if (Length(x, y) <= radius1 + radius2) {
		return true;
	} else {
		// そうでなければfalseを返す
		return false;
	}
}

int IsRect2RectHit(float x1, float y1, float width1, float height1, float x2, float y2, float width2, float height2) {
	if (x1 < x2 + width2 &&
		x2 < x1 + width1 &&
		y1 < y2 + height2 &&
		y2 < y1 + height1) {
		return true;
	} else {
		return false;
	}
}

int IsPos2CircleHit(float posX, float posY, float circleX, float circleY, float circleRadius) {
	float x = circleX - posX;
	float y = circleY - posY;

	// 円の半径よりも中心点間の距離のほうが短いならtrueを返す
	if (Length(x, y) <= circleRadius) {
		return true;
	} else {
		// そうでなければfalseを返す
		return false;
	}
}

int IsPos2RectHit(float posX, float posY, float rectX, float rectY, float rectWidth, float rectHeight) {
	if (posX < rectX + rectWidth &&
		rectX < posX &&
		posY < rectY + rectHeight &&
		rectY < posY) {
		return true;
	} else {
		return false;
	}
}

int IsCircle2RectHit(float circleX, float circleY, float radius, float rectX, float rectY, float width, float height) {
	int isHit = false;

	// 四角形の四辺に対して円の半径分だけ足したとき円が重なっていたら
	if ((circleX > rectX - radius) &&
		(circleX < rectX + width + radius) &&
		(circleY > rectY - radius) &&
		(circleY < rectY + height + radius)) {
		isHit = true;

		// 左
		if (circleX < rectX) {
			// 左上
			if (circleY < rectY) {
				if (!IsPos2CircleHit(circleX, circleY, rectX, rectY, radius)) {
					isHit = false;
				}
			} else {
				// 左下
				if (circleY > rectY + height) {
					if (!IsPos2CircleHit(circleX, circleY, rectX, rectY + height, radius)) {
						isHit = false;
					}
				}
			}
		} else {
			// 右
			if (circleX > rectX + width) {
				// 右上
				if (circleY < rectY) {
					if (!IsPos2CircleHit(circleX, circleY, rectX + width, rectY, radius)) {
						isHit = false;
					}
				} else {
					// 右下
					if (circleY > rectY + height) {
						if (!IsPos2CircleHit(circleX, circleY, rectX + width, rectY + height, radius)) {
							isHit = false;
						}
					}
				}
			}
		}
	}

	return isHit;
}

int IsCircle2CapsuleHit(float circleX, float circleY, float circleRadius, float capsuleX1, float capsuleY1, float capsuleX2, float capsuleY2, float capsuleRadius) {
	Vector2 d = {
		circleX - capsuleX1,
		circleY - capsuleY1
	};
	Vector2 ba = {
		capsuleX2 - capsuleX1,
		capsuleY2 - capsuleY1
	};
	// baを正規化
	Vector2 e = Normalize(ba.x, ba.y);
	// tの値を求める
	float t = DotProduct(d.x, d.y, e.x, e.y) / Length(ba.x, ba.y);
	// tを0～1の範囲に収める
	t = Clamp(t, 0.0f, 1.0f);
	// 線形補完
	Vector2 f = {
		(1.0f - t) * capsuleX1 + t * capsuleX2,
		(1.0f - t) * capsuleY1 + t * capsuleY2
	};
	// 距離を求める
	float distance = Length(circleX - f.x, circleY - f.y);
	// 円とカプセルの半径の合計よりもc-fの長さが短ければ衝突
	if (distance < circleRadius + capsuleRadius) {
		// 衝突していたらtrueを返す
		return true;
	} else {
		// 衝突していなかったらfalseを返す
		return false;
	}
}

int IsOutsideAreaCircle(float circleX, float circleY, float radius, float areaX, float areaY, float areaWidth, float areaHeight) {
	if (circleX - radius < areaX ||
		circleY - radius < areaY ||
		circleX + radius > areaX + areaWidth ||
		circleY + radius > areaY + areaHeight) {
		return true;
	} else {
		return false;
	}
}

int IsOutsideAreaRect(float rectX, float rectY, float rectWidth, float rectHeight, float areaX, float areaY, float areaWidth, float areaHeight) {
	if (rectX < areaX ||
		rectY < areaY ||
		rectX + rectWidth > areaX + areaWidth ||
		rectY + rectHeight > areaY + areaHeight) {
		return true;
	} else {
		return false;
	}
}

Vector2 RotatePos(float rotateX, float rotateY, float originX, float originY, float theta) {
	return {
		originX + ((rotateX - originX) * cosf(theta) - (rotateY - originY) * sinf(theta)),
		originY + ((rotateY - originY) * cosf(theta) + (rotateX - originX) * sinf(theta)),
	};
}

float ConvertWCX(float posX, float worldOriginPosX) {
	return worldOriginPosX + posX;
}

float ConvertWCY(float posY, float worldOriginPosY) {
	return worldOriginPosY - posY;
}

float ConvertInt2Time(int nowT, int endT) {
	// 割る値が 0 なら強制的に 1.0f を返す
	if (endT == 0) {
		return 1.0f;
	} else {
		// 値が必ず 0.0f ～ 1.0f になるようにする
		return Clamp(static_cast<float>(nowT) / static_cast<float>(endT), 0.0f, 1.0f);
	}
}

float ConvertFloat2Time(float nowT, float endT) {
	// 割る値が 0.0f なら強制的に 1.0f を返す
	if (endT == 0.0f) {
		return 1.0f;
	} else {
		// 値が必ず 0.0f ～ 1.0f になるようにする
		return Clamp(static_cast<float>(nowT) / static_cast<float>(endT), 0.0f, 1.0f);
	}
}

float EaseIn(float t, float x1, float x2) {
	float easedT = powf(Clamp(t, 0.0f, 1.0f), 2.0f);
	return (1.0f - easedT) * x1 + easedT * x2;
}

float EaseOut(float t, float x1, float x2) {
	float easedT = 1.0f - powf(1.0f - Clamp(t, 0.0f, 1.0f), 3.0f);
	return (1.0f - easedT) * x1 + easedT * x2;
}

float EaseInOut(float t, float x1, float x2) {
	float easedT = -(cosf(M_PI + Clamp(t, 0.0f, 1.0f)) - 1.0f) / 2.0f;
	return (1.0f - easedT) * x1 + easedT * x2;
}