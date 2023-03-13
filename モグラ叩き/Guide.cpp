#include "Guide.h"
#include "Main.h"

void GUIDE::Update() {
	font(U"モグラが掲げている看板と同じキーを打とう").drawAt(X_MAX / 2, Y_MAX / 2 - 50);
	font(U"モグラが看板を出してから一定時間経過するとゲームオーバーだよ").drawAt(X_MAX / 2, Y_MAX / 2);
}
