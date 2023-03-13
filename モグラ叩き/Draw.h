#pragma once
#include "Main.h"
#include "MyType.h"

class DRAW {
	const Texture g_Seat{ Resource(U"rom/MoguratatakiSeat.png") };
	const Audio audio{ Audio::Stream,Resource(U"rom/boko.mp3") };
	const Audio audio1{ Audio::Stream,Resource(U"rom/stage.mp3"),Loop::Yes };

public:
	void CircleDraw(VECTOR2 pos);
	void PlayerDraw(int num,VECTOR2 pos);
	void EnemyDraw(int num, VECTOR2 pos);
	void GroundDraw();
	void AudioPlay();
	void AudioStop();
	void Audio1Play();
	void Audio1Stop();
};
