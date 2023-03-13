#pragma once
#include "Main.h"
#include "Player.h"
#include "Enemy.h"
#include "Score.h"
#include "MyTime.h"
#include "Draw.h"
#include "ScoreDisp.h"

enum GAME_STATE {
	PLAY,
	GAME_END
};

#define CIRCLE_MAX	(8)

struct ALPHABET {
	bool use;
	int alphabetNum;
	bool hit;
};

class GAME {
	VECTOR2 circlePos[CIRCLE_MAX];
	PLAYER* pplayer;
	ENEMY* penemy[CIRCLE_MAX];
	SCORE* pscore;
	DRAW* pdraw;
	MY_TIME* ptime;
	SCORE_DISP scoreDisp;
	int gameState;	//今どの場面なのか
	float attackTimeLimeit;	//何秒以内に攻撃をするか
	ALPHABET alphabet[CIRCLE_MAX];	//表示するalphabet
	const Font font{ 32 };
	bool limitFlag;

public:
	GAME();
	~GAME();
	void PointerInit(DRAW* pdraw,MY_TIME* ptime, SCORE* pscore,int* state);	//ポインタの初期化
	void Init();	//初期化関数
	void Update();	//アップデート関数
	void GetKey();
	void GetAlphabet(int num);	//表示するalphabetを取得
	void Draw();
};
