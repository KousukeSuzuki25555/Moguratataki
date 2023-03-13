#include "Enemy.h"

ENEMY::ENEMY() {
	pos = { 0.0f,0.0f };
	ptime = 0;
	pdraw = 0;
	gNum = 0;
	attackInitTime = 0.0f;
	attackTime = 0.0f;
	attackUninitTime = 0.0f;
	attackFlag = false;
	exist = false;
	drawFlag = false;
}

void ENEMY::PointerInit(DRAW* pdraw, MY_TIME* ptime) {	//ポインタの初期化
	this->pdraw = pdraw;
	this->ptime = ptime;
}

void ENEMY::Init(VECTOR2 pos) {	//初期化関数
	this->pos = pos;
	gNum = 0;
	attackInitTime = ptime->GetTime() + (Random(100)/10);
	attackTime = ptime->GetTime()+100.0f;
	attackUninitTime = ptime->GetTime()+100.0f;
	attackFlag = false;
	exist = true;
	drawFlag = false;
}

void ENEMY::Update() {	//アップデート関数
	if (attackInitTime < ptime->GetTime()) {
		Attack();
	}

	if (attackTime < ptime->GetTime()) {
		AttackAct();
	}

	if (attackUninitTime < ptime->GetTime()) {
		AttackUninit();
	}
}

void ENEMY::Attack() {			//頭を出すときに呼び出す
	gNum = 0;
	attackTime = ptime->GetTime() + (rand() % 80) / 10;
	attackInitTime = ptime->GetTime() + 100.0f;
	drawFlag = true;
}

void ENEMY::AttackAct() {		//攻撃をするときに呼び出す
	gNum = 1;
	attackUninitTime = ptime->GetTime() + 3.0f;
	attackFlag = true;
	attackTime = ptime->GetTime() + 100.0f;
}

void ENEMY::AttackUninit(int attack) {	//攻撃から抜ける
	gNum = 2;
	attackFlag = false;
	attackInitTime = ptime->GetTime() + (Random(attack*10) / 10);
	attackUninitTime = ptime->GetTime() + 100;
	drawFlag = false;
}

void ENEMY::AttackUninit() {	//時間が経過して抜ける場合
	exist = false;
}

bool ENEMY::GetAttack() {	//攻撃が終了しているか
	return attackFlag;
}

bool ENEMY::GetExist() {
	return exist;
}

void ENEMY::Draw() {
	if (drawFlag == true) {
		pdraw->EnemyDraw(gNum, pos);
	}
}
