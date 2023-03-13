#pragma once
#include "Main.h"
#include "Game.h"
#include "Score.h"

//enum CURSOR_POS {
//	START=Y_MAX/2+50,
//	EXP=Y_MAX/2+100,
//	RIGHTS=Y_MAX/2+150,	//権利表記
//	SAVE=Y_MAX / 2 + 200,
//	RANK= Y_MAX / 2 + 250,
//	FINISH=Y_MAX / 2 + 300
//};

class TITLE {
	const Font font48{ 48 };
	const Font font32{ 32 };
	int cursorPos;
	int* state;
	bool* finish;
	GAME* pgame;
	SCORE* pscore;

public:
	TITLE();
	void PointerInit(int* state,bool* finish, GAME* pgame,SCORE* pscore);
	void Init();
	void Update();
	void KeyGet();
	void Draw();
};
