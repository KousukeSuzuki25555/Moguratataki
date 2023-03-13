#include "Game.h"

GAME::GAME() {
	for (int e = 0; e < CIRCLE_MAX; e++) {
		circlePos[e] = { cosf(e * 0.25 * PI) * 200 + X_MAX / 2,
			sinf(e * 0.25 * PI) * 200 + Y_MAX / 2 };
		penemy[e] = new ENEMY;
		alphabet[e].use = false;
		alphabet[e].alphabetNum = 0;
		alphabet[e].hit = false;
	}
	pplayer = new PLAYER;
	//pscore = new SCORE;
	gameState = PLAY;	//今どの場面なのか
	attackTimeLimeit = 0;
	limitFlag = false;
}


GAME::~GAME() {
	delete pplayer;
	//delete pscore;
	for (int e = 0; e < CIRCLE_MAX; e++) {
		delete penemy[e];
	}
	//delete ptime;
}

void GAME::PointerInit(DRAW* pdraw,MY_TIME* ptime, SCORE* pscore,int* state){	//ポインタの初期化
	this->pdraw = pdraw;
	this->ptime = ptime;
	this->pscore = pscore;
	pplayer->PointerInit(pdraw, ptime);
	for (int e = 0; e < CIRCLE_MAX; e++) {
		penemy[e]->PointerInit(pdraw, ptime);
	}
	scoreDisp.PointerInit(pscore,state);
	attackTimeLimeit = 10;
}

void GAME::Init() {	//初期化関数
	pscore->Init();
	pplayer->Init();
	for (int e = 0; e < CIRCLE_MAX; e++) {
		penemy[e]->Init(circlePos[e]);
		alphabet[e].use = false;
		GetAlphabet(e);
		alphabet[e].hit = false;
	}
	gameState = PLAY;	//今どの場面なのか
	limitFlag = true;
	pdraw->Audio1Play();
}

void GAME::Update() {	//アップデート関数
	switch (gameState) {
	case PLAY: {
		GetKey();

		//Playerの動き
		for (int e = 0; e < CIRCLE_MAX; e++) {
			if (alphabet[e].hit == true) {
				VECTOR2 ppos = circlePos[e];
				ppos.x -= 32;
				pplayer->Attack(ppos);
				penemy[e]->AttackUninit(attackTimeLimeit);
				alphabet[e].hit = false;
				alphabet[e].use = false;
				pscore->SetScore();
			}
		}
		pplayer->Update();

		//敵の動き
		for (int e = 0; e < CIRCLE_MAX; e++) {
			/*if (alphabet[e].hit == true) {
				penemy[e]->AttackUninit(attackTimeLimeit);
				alphabet[e].hit = false;
			}*/
			penemy[e]->Update();
			if (penemy[e]->GetAttack() == true) {
				alphabet[e].use = true;
			}
			if (penemy[e]->GetExist() == false) {
				pscore->Uninit();
				gameState = GAME_END;
				pdraw->Audio1Stop();
				break;
			}
		}

		if (pscore->GetScore() % 10 == 0 && limitFlag == false) {	//スコアが10の倍数になったら出現時間を短縮する
			attackTimeLimeit--;
			if (attackTimeLimeit < 1) {
				attackTimeLimeit = 1;
			}
			limitFlag = true;
		}
		else if (pscore->GetScore() % 10 == 1 && limitFlag == true) {	//スコアが11になったらフラグを解除
			limitFlag = false;
		}

		Draw();
		break;
	}
	case GAME_END:
		scoreDisp.Update();
		Draw();
		break;
	}
}

void GAME::GetKey() {
	int a = 100;
	if (KeyA.down()) {
		a = A;
	}
	else if (KeyB.down()) {
		a = B;
	}
	else if (KeyC.down()) {
		a = C;
	}
	else if (KeyD.down()) {
		a = D;
	}
	else if (KeyE.down()) {
		a = E;
	}
	else if (KeyF.down()) {
		a = F;
	}
	else if (KeyG.down()) {
		a = G;
	}
	else if (KeyH.down()) {
		a = H;
	}
	else if (KeyI.down()) {
		a = I;
	}
	else if (KeyJ.down()) {
		a = J;
	}
	else if (KeyK.down()) {
		a = K;
	}
	else if (KeyL.down()) {
		a = L;
	}
	else if (KeyM.down()) {
		a = M;
	}
	else if (KeyN.down()) {
		a = N;
	}
	else if (KeyO.down()) {
		a = O;
	}
	else if (KeyP.down()) {
		a = P;
	}
	else if (KeyQ.down()) {
		a = Q;
	}
	else if (KeyR.down()) {
		a = R;
	}
	else if (KeyS.down()) {
		a = S;
	}
	else if (KeyT.down()) {
		a = T;
	}
	else if (KeyU.down()) {
		a = U;
	}
	else if (KeyV.down()) {
		a = V;
	}
	else if (KeyW.down()) {
		a = W;
	}
	else if (KeyX.down()) {
		a = X;
	}
	else if (KeyY.down()) {
		a = Y;
	}
	else if (KeyZ.down()) {
		a = Z;
	}

	for (int e = 0; e < CIRCLE_MAX; e++) {
		if (alphabet[e].alphabetNum == a&&alphabet[e].use==true) {
			alphabet[e].hit = true;
			return;
		}
	}
}

void GAME::GetAlphabet(int num) {	//表示するalphabetを取得
	alphabet[num].alphabetNum = Random(25);
}

void GAME::Draw() {
	switch (gameState) {
	case PLAY:
		pdraw->GroundDraw();
		pplayer->Draw();
		for (int e = 0; e < CIRCLE_MAX; e++) {
			pdraw->CircleDraw(circlePos[e]);
			penemy[e]->Draw();

			if (alphabet[e].use == true) {
				if (alphabet[e].alphabetNum == A) {
					VECTOR2 pos = circlePos[e];
					pos.x += 32.0f;
					pos.y -= 16.0f;
					font(U"A").drawAt(pos.x,pos.y);
				}
				if (alphabet[e].alphabetNum == B) {
					VECTOR2 pos = circlePos[e];
					pos.x += 32.0f;
					pos.y -= 16.0f;
					font(U"B").drawAt(pos.x, pos.y);
				}
				if (alphabet[e].alphabetNum == C) {
					VECTOR2 pos = circlePos[e];
					pos.x += 32.0f;
					pos.y -= 16.0f;
					font(U"C").drawAt(pos.x, pos.y);
				}
				if (alphabet[e].alphabetNum == D) {
					VECTOR2 pos = circlePos[e];
					pos.x += 32.0f;
					pos.y -= 16.0f;
					font(U"D").drawAt(pos.x, pos.y);
				}
				if (alphabet[e].alphabetNum == E) {
					VECTOR2 pos = circlePos[e];
					pos.x += 32.0f;
					pos.y -= 16.0f;
					font(U"E").drawAt(pos.x, pos.y);
				}
				if (alphabet[e].alphabetNum == F) {
					VECTOR2 pos = circlePos[e];
					pos.x += 32.0f;
					pos.y -= 16.0f;
					font(U"F").drawAt(pos.x, pos.y);
				}
				if (alphabet[e].alphabetNum == G) {
					VECTOR2 pos = circlePos[e];
					pos.x += 32.0f;
					pos.y -= 16.0f;
					font(U"G").drawAt(pos.x, pos.y);
				}
				if (alphabet[e].alphabetNum == H) {
					VECTOR2 pos = circlePos[e];
					pos.x += 32.0f;
					pos.y -= 16.0f;
					font(U"H").drawAt(pos.x, pos.y);
				}
				if (alphabet[e].alphabetNum == I) {
					VECTOR2 pos = circlePos[e];
					pos.x += 32.0f;
					pos.y -= 16.0f;
					font(U"I").drawAt(pos.x, pos.y);
				}
				if (alphabet[e].alphabetNum == J) {
					VECTOR2 pos = circlePos[e];
					pos.x += 32.0f;
					pos.y -= 16.0f;
					font(U"J").drawAt(pos.x, pos.y);
				}
				if (alphabet[e].alphabetNum == K) {
					VECTOR2 pos = circlePos[e];
					pos.x += 32.0f;
					pos.y -= 16.0f;
					font(U"K").drawAt(pos.x, pos.y);
				}
				if (alphabet[e].alphabetNum == L) {
					VECTOR2 pos = circlePos[e];
					pos.x += 32.0f;
					pos.y -= 16.0f;
					font(U"L").drawAt(pos.x, pos.y);
				}
				if (alphabet[e].alphabetNum == M) {
					VECTOR2 pos = circlePos[e];
					pos.x += 32.0f;
					pos.y -= 16.0f;
					font(U"M").drawAt(pos.x, pos.y);
				}
				if (alphabet[e].alphabetNum == N) {
					VECTOR2 pos = circlePos[e];
					pos.x += 32.0f;
					pos.y -= 16.0f;
					font(U"N").drawAt(pos.x, pos.y);
				}
				if (alphabet[e].alphabetNum == O) {
					VECTOR2 pos = circlePos[e];
					pos.x += 32.0f;
					pos.y -= 16.0f;
					font(U"O").drawAt(pos.x, pos.y);
				}
				if (alphabet[e].alphabetNum == P) {
					VECTOR2 pos = circlePos[e];
					pos.x += 32.0f;
					pos.y -= 16.0f;
					font(U"P").drawAt(pos.x, pos.y);
				}
				if (alphabet[e].alphabetNum == Q) {
					VECTOR2 pos = circlePos[e];
					pos.x += 32.0f;
					pos.y -= 16.0f;
					font(U"Q").drawAt(pos.x, pos.y);
				}
				if (alphabet[e].alphabetNum == R) {
					VECTOR2 pos = circlePos[e];
					pos.x += 32.0f;
					pos.y -= 16.0f;
					font(U"R").drawAt(pos.x, pos.y);
				}
				if (alphabet[e].alphabetNum == S) {
					VECTOR2 pos = circlePos[e];
					pos.x += 32.0f;
					pos.y -= 16.0f;
					font(U"S").drawAt(pos.x, pos.y);
				}
				if (alphabet[e].alphabetNum == T) {
					VECTOR2 pos = circlePos[e];
					pos.x += 32.0f;
					pos.y -= 16.0f;
					font(U"T").drawAt(pos.x, pos.y);
				}
				if (alphabet[e].alphabetNum == U) {
					VECTOR2 pos = circlePos[e];
					pos.x += 32.0f;
					pos.y -= 16.0f;
					font(U"U").drawAt(pos.x, pos.y);
				}
				if (alphabet[e].alphabetNum == V) {
					VECTOR2 pos = circlePos[e];
					pos.x += 32.0f;
					pos.y -= 16.0f;
					font(U"V").drawAt(pos.x, pos.y);
				}
				if (alphabet[e].alphabetNum == W) {
					VECTOR2 pos = circlePos[e];
					pos.x += 32.0f;
					pos.y -= 16.0f;
					font(U"W").drawAt(pos.x, pos.y);
				}
				if (alphabet[e].alphabetNum == X) {
					VECTOR2 pos = circlePos[e];
					pos.x += 32.0f;
					pos.y -= 16.0f;
					font(U"X").drawAt(pos.x, pos.y);
				}
				if (alphabet[e].alphabetNum == Y) {
					VECTOR2 pos = circlePos[e];
					pos.x += 32.0f;
					pos.y -= 16.0f;
					font(U"Y").drawAt(pos.x, pos.y);
				}
				if (alphabet[e].alphabetNum == Z) {
					VECTOR2 pos = circlePos[e];
					pos.x += 32.0f;
					pos.y -= 16.0f;
					font(U"Z").drawAt(pos.x, pos.y);
				}

			}
		}
		

		break;
	case GAME_END:
		scoreDisp.Draw();
		break;
	}
}
