#include "Title.h"

TITLE::TITLE() {
	cursorPos = START;
	state = 0;
	pgame = 0;
}

void TITLE::PointerInit(int* state,bool* finish, GAME* pgame,SCORE* pscore) {
	this->state = state;
	this->finish = finish;
	this->pgame = pgame;
	this->pscore = pscore;
}

void TITLE::Init() {
	cursorPos = START ;
}

void TITLE::Update() {
	KeyGet();

	if (KeyEnter.down()) {
		switch (cursorPos) {
		case START:
			*state = START;
			pgame->Init();
			break;

		case EXP:
			*state = EXP;

			break;

		case RIGHTS:
			*state = RIGHTS;

			break;

		case SAVE:
			*state = SAVE;

			break;

		case RANK:
			*state = RANK;

			break;

		case FINISH:
			*state = FINISH;
			break;

		}
	}
}

void TITLE::KeyGet() {
	if (KeyDown.down()) {
		switch (cursorPos) {
		case START:
			cursorPos = EXP;
			break;

		case EXP:
			cursorPos = RIGHTS;
			break;

		case RIGHTS:
			cursorPos = SAVE;
			break;

		case SAVE:
			cursorPos = RANK;
			break;

		case RANK:
			cursorPos=FINISH;
			break;

		case FINISH:
			cursorPos = START;
			break;
		}
	}
	else if (KeyUp.down()) {
		switch (cursorPos) {
		case START:
			cursorPos = FINISH;
			break;

		case EXP:
			cursorPos = START;
			break;

		case RIGHTS:
			cursorPos = EXP;
			break;

		case SAVE:
			cursorPos = RIGHTS;
			break;

		case RANK:
			cursorPos = SAVE;
			break;

		case FINISH:
			cursorPos = RANK;
			break;
		}
	}
}

void TITLE::Draw() {
	font48(U"モグラたたき").drawAt(X_MAX / 2, Y_MAX / 2 - 100);
	font32(U"START").drawAt(X_MAX / 2, START);
	font32(U"操作説明").drawAt(X_MAX / 2, EXP);
	font32(U"権利表記").drawAt(X_MAX / 2, RIGHTS);
	font32(U"セーブ").drawAt(X_MAX / 2, SAVE);
	font32(U"ランキング").drawAt(X_MAX / 2, RANK);
	font32(U"終了").drawAt(X_MAX / 2, FINISH);
	font32(U"▶").drawAt(X_MAX / 2 - 100, cursorPos);
}
