#include "Main.h"
#include "MyTime.h"
#include "Game.h"
#include "Draw.h"
#include "Title.h"
#include "Score.h"
#include "Rights.h"
#include "Guide.h"

#define X_MAX	(1280)		//画面横の大きさ
#define Y_MAX	(720)		//画面縦の大きさ

void Main()
{
	srand((unsigned)time(NULL));
	Window::Resize(X_MAX, Y_MAX);		//画面サイズの変更
	GAME* pgame = new GAME;
	MY_TIME* ptime = new MY_TIME;
	DRAW* pdraw = new DRAW;
	TITLE* ptitle = new TITLE;
	SCORE* pscore = new SCORE;
	int* pstate = new int;
	*pstate = S_TITLE;
	bool* finish = new bool;
	*finish = false;
	RIGHT right;
	GUIDE guide;

	pgame->PointerInit(pdraw, ptime,pscore,pstate);
	//pgame->Init();
	ptitle->PointerInit(pstate,finish, pgame,pscore);
	ptitle->Init();

	pscore->LoadSave();

	while (System::Update())
	{
		ptime->Update();

		switch (*pstate) {
		case S_TITLE:
			ptitle->Update();
			ptitle->Draw();
			break;

		case START:
			pgame->Update();
			break;

		case EXP:
			guide.Update();
			if (KeyEnter.down()) {
				*pstate = S_TITLE;
			}
			break;

		case RIGHTS:
			right.Update();
			if (KeyEnter.down()) {
				*pstate = S_TITLE;
			}
			break;

		case RANK:
			pscore->RankUpdate();
			if (KeyEnter.down()) {
				*pstate = S_TITLE;
			}
			break;

		case SAVE:
			pscore->SaveData();
			*pstate = S_TITLE;
			break;
		}

		if (*pstate==FINISH) {
			break;
		}
	}
	delete pgame;
	delete ptitle;
	delete pscore;
	delete pstate;
	delete pdraw;
	delete ptime;
}
