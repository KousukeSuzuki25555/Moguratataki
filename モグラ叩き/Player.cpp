#include "Player.h"

PLAYER::PLAYER() {
	pos = { 0.0f,0.0f };
	gNum = 0;	//何番目の絵を使用するか
	attackTime = 0.0f;	//攻撃に使用する時間変数
}

void PLAYER::PointerInit(DRAW* pdraw, MY_TIME* ptime) {	//ポインタの初期化関数
	this->pdraw = pdraw;
	this->ptime = ptime;
}

void PLAYER::Init() {	//初期化関数
	pos = { X_MAX / 2,Y_MAX / 2 };
	gNum = 0;
	attackTime = 0.0f;
}

void PLAYER::Update() {	//アップデート関数
	if (attackTime < ptime->GetTime()) {
		AttackUninit();
	}
}

void PLAYER::Attack(VECTOR2 pos) {	//攻撃を呼び出すとき
	pdraw->AudioStop();
	pdraw->AudioPlay();
	gNum = 1;
	this->pos = pos;
	attackTime = ptime->GetTime() + 0.2f;	//攻撃から抜け出す時間をセット
}

void PLAYER::AttackUninit() {	//攻撃から抜け出す
	gNum = 0;
	pos = { X_MAX / 2,Y_MAX / 2 };
}

void PLAYER::Draw() {	//描画関数
	pdraw->PlayerDraw(gNum, pos);
}
