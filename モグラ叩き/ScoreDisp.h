#pragma once
#include "Score.h"

class SCORE_DISP {
	const Font font{ 32 };
	SCORE* pscore;
	int* state;

public:
	void PointerInit(SCORE* pscore,int* state);
	void Update();
	void Draw();
};
