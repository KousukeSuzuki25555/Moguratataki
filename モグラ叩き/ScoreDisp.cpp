#include "ScoreDisp.h"
#include "Main.h"

void SCORE_DISP::PointerInit(SCORE* pscore,int* state) {
	this->pscore = pscore;
	this->state = state;
}

void SCORE_DISP::Update() {
	if (KeyEnter.down()) {
		*state = S_TITLE;
	}
}

void SCORE_DISP::Draw() {
	font(U"SCORE").drawAt(X_MAX / 2, Y_MAX / 2);
	font(pscore->GetScore(),  U"点").drawAt(X_MAX / 2, Y_MAX / 2 + 100);
}
