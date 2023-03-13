#include "Draw.h"

void DRAW::CircleDraw(VECTOR2 pos) {
	g_Seat(128*G_SIZE/STANDARD_SIZE, 0, 63.9f * G_SIZE / STANDARD_SIZE, 63.9f * G_SIZE / STANDARD_SIZE).drawAt(pos.x, pos.y);
}

void DRAW::PlayerDraw(int num, VECTOR2 pos) {
	g_Seat(num * 64 * G_SIZE / STANDARD_SIZE, 0, 64 * G_SIZE / STANDARD_SIZE, 64 * G_SIZE / STANDARD_SIZE).drawAt(pos.x, pos.y);
}

void DRAW::EnemyDraw(int num, VECTOR2 pos) {
	switch (num) {
	case 0:
		g_Seat(0, 64 * G_SIZE / STANDARD_SIZE, 64 * G_SIZE / STANDARD_SIZE, 64 * G_SIZE / STANDARD_SIZE).drawAt(pos.x, pos.y);
		break;
	case 1:
		g_Seat(64 * G_SIZE / STANDARD_SIZE, 64 * G_SIZE / STANDARD_SIZE, 128 * G_SIZE / STANDARD_SIZE, 64 * G_SIZE / STANDARD_SIZE).drawAt(pos.x, pos.y);
		break;
	case 2:
		g_Seat(192 * G_SIZE / STANDARD_SIZE, 64 * G_SIZE / STANDARD_SIZE, 64 * G_SIZE / STANDARD_SIZE, 64 * G_SIZE / STANDARD_SIZE).drawAt(pos.x, pos.y);
		break;
	}
}

void DRAW::GroundDraw() {
	g_Seat(256 - 16, 0, 16, 9).scaled(80).draw(0.0f, 0.0f);
}

void DRAW::AudioPlay() {
	audio.play();
}

void DRAW::AudioStop() {
	audio.stop();
}

void DRAW::Audio1Play() {
	audio1.setVolume(0.5);
	audio1.play();
}

void DRAW::Audio1Stop() {
	audio1.stop();
}
