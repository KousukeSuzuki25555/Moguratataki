#pragma once
# include <Siv3D.hpp>
#include "MyType.h"
#include "Time.h"
#include "stdlib.h"

#define X_MAX	(1280)		//画面横の大きさ
#define Y_MAX	(720)		//画面縦の大きさ
#define PI	(3.1415926535f)	//π
#define G_SIZE	(64)
#define STANDARD_SIZE	(64)

enum TITLE_STATE {
	S_TITLE,
	START = Y_MAX / 2 + 50,
	EXP = Y_MAX / 2 + 100,
	RIGHTS = Y_MAX / 2 + 150,	//権利表記
	SAVE = Y_MAX / 2 + 200,
	RANK = Y_MAX / 2 + 250,
	FINISH = Y_MAX / 2 + 300
};

enum Key{
	A,
	B,
	C,
	D,
	E,
	F,
	G,
	H,
	I,
	J,
	K,
	L,
	M,
	N,
	O,
	P,
	Q,
	R,
	S,
	T,
	U,
	V,
	W,
	X,
	Y,
	Z
};
