#pragma once
#include "Main.h"
#include "MyTime.h"
#include "Draw.h"

class ENEMY {
	VECTOR2 pos;
	MY_TIME* ptime;
	DRAW* pdraw;
	int gNum;
	float attackInitTime;
	float attackTime;
	float attackUninitTime;
	bool attackFlag;
	bool exist;
	bool drawFlag;

public:
	ENEMY();
	void PointerInit(DRAW* pdraw,MY_TIME* ptime);	//ポインタの初期化
	void Init(VECTOR2 pos);	//初期化関数
	void Update();	//アップデート関数
	void Attack();			//頭を出すときに呼び出す
	void AttackAct();		//攻撃をするときに呼び出す
	void AttackUninit(int attack);	//攻撃から抜ける	attack=抜ける時間
	void AttackUninit();	//時間が経過して抜ける場合
	bool GetAttack();	//攻撃が終了しているか
	bool GetExist();
	void Draw();
};
