#pragma once
#include "Structures.h"

/// <summary>
/// 指定の範囲で乱数を生成する関数
/// </summary>
/// <param name="min">乱数の最小値</param>
/// <param name="max">乱数の最大値</param>
/// <returns>min ～ max までの乱数</returns>
int RandRange(int min, int max);

/// <summary>
/// ベクトルの長さを求める関数
/// </summary>
/// <param name="vector">長さを求めたいベクトル</param>
/// <returns>ベクトルの長さ</returns>
float Length(const Vector2 &vector);

/// <summary>
/// ベクトルの長さを正規化する
/// </summary>
/// <param name="vector">ベクトル座標 </param>
/// <returns>成功: 正規化したベクトル  失敗: 0</returns>
Vector2 Normalize(const Vector2 &vector);

/// <summary>
/// ベクトルの内積を求める
/// </summary>
/// <param name="vec1">ベクトル座標1</param>
/// <param name="vec2">ベクトル座標2</param>
/// <returns>float型の内積の値</returns>
float DotProduct(const Vector2 &vec1, const Vector2 &vec2);

/// <summary>
/// 渡された小数値を指定の範囲に収める
/// </summary>
/// <param name="t">指定の範囲に収める値</param>
/// <param name="min">最低値</param>
/// <param name="max">最大値</param>
/// <returns>minとmaxの間に収めたt</returns>
float Clamp(float t, float min, float max);
