#pragma once
#include "Main.h"
#include "Draw.h"
#include "MyTime.h"

class PLAYER {
	VECTOR2 pos;
	DRAW* pdraw;
	MY_TIME* ptime;
	int gNum;	//何番目の絵を使用するか
	float attackTime;	//攻撃に使用する時間変数

public:
	PLAYER();
	void PointerInit(DRAW* pdraw, MY_TIME* ptime);	//ポインタの初期化関数
	void Init();	//初期化関数
	void Update();	//アップデート関数
	void Attack(VECTOR2 pos);	//攻撃を呼び出すとき
	void AttackUninit();	//攻撃から抜け出す
	void Draw();	//描画関数
};
