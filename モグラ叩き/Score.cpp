#include "Main.h"
#include "Score.h"
#include "stdlib.h"

#define SCORE_X	(X_MAX/2)
#define RANK_X	(X_MAX/3)
#define STANDARD	(50)

SCORE::SCORE() {	//コンストラクタ
	array = new ST_SCORE;
	s_array = array;
	MakeFirstArray();
}

SCORE::~SCORE() {	//デストラクタ
	delete s_array;
}

void SCORE::SaveData() {				//データをセーブする関数
	fopen_s(&save_file, file_name, "wb");
	if (save_file == NULL) {				//ファイルが開けないとき
		font(U"セーブファイルが開けませんでした");
	}
	else {
		int num = CountArray();
		fwrite(&num, sizeof(int), 1, save_file);

		MoveFirst();
		for (int e = 0; e < num; e++) {
			fwrite(&array->score, sizeof(int), 1, save_file);
			if (array->next != NULL) {
				array = array->next;
			}
		}
	}
	fclose(save_file);
}

void SCORE::LoadSave() {				//データをロードする関数 最初にリストの数をintで渡し、要素数を確保
	fopen_s(&save_file, file_name, "rb");
	if (save_file == NULL) {				//ファイルが開けないとき　新しいセーブデータを生成する
		SaveData();
	}
	else {
		int num = 0;
		fread(&num, sizeof(int), 1, save_file);

		for (int e = 0; e < num-1; e++) {
			fread(&array->score, sizeof(int), 1, save_file);

			if (e != num - 1) {
				ST_SCORE* newArray = MakeArray();
				ArrayInit(newArray);
				array->next = newArray;
				newArray->before = array;

				array = array->next;
			}
		}
	}
	fclose(save_file);
}

void SCORE::Init() {	//初期化
	gameScore = 0;
}

void SCORE::Uninit() {	//抜ける処理
	ScoreIn();
}

void SCORE::SetScore() {	//敵を倒したときにscoreを増やす
	gameScore++;
}

int SCORE::GetScore() {	//scoreのゲッター
	return gameScore;
}

void SCORE::MakeFirstArray() {	//最初の要素を作る
	array->before = array->next = NULL;
	array->score = 0;
}

ST_SCORE* SCORE::MakeArray() {	//要素を追加する
	ST_SCORE* newArray = (ST_SCORE*)calloc(1, sizeof(ST_SCORE));
	return newArray;
}

void SCORE::MoveFirst() {	//要素の一番最初へ移動する
	if (array->before == NULL) {
		return;
	}
	while (array ->before != NULL) {
		array = array->before;
	}
}

void SCORE::MoveLast() {	//要素の最後へ移動する
	if (array->next == NULL) {
		return;
	}
	while (array->next != NULL) {
		array = array->next;
	}
}

int SCORE::CountArray() {	//要素の数を数える
	int num=1;
	MoveFirst();
	if (array->next == NULL) {
		return num;
	}
	while (array->next != NULL) {
		num++;
		array = array->next;
	}
	return num;
}

void SCORE::ScoreIn() {	//要素にスコアを入れる
	int num = CountArray();
	MoveFirst();


	for (int e = 0; e < num; e++) {
		if (array->score < gameScore) {
			if (array->before == NULL) {
				ST_SCORE* newArray = MakeArray();	//要素を付け替える処理
				ArrayInit(newArray);
				newArray->score = gameScore;
				array->before = newArray;
				newArray->next = array;
				return;
			}

			ST_SCORE* newArray = MakeArray();	//要素を付け替える処理
			ArrayInit(newArray);
			newArray->score = gameScore;
			array->before->next = newArray;
			newArray->before = array->before;
			newArray->next = array;
			array->before = newArray;

			if (num >= 11) {	//10個以上だったら一番最後の要素を削除する
				MoveLast();
				array = array->before;
				array->next->before = NULL;
				array->next = NULL;
			}
			return;
		}
		if (array->next == NULL) {
			break;
		}
		array = array->next;
	}
	if (num < 11) {
		//MoveLast();
		ST_SCORE* newArray = MakeArray();	//要素を付け替える処理
		ArrayInit(newArray);
		newArray->score = gameScore;
		array->next = newArray;
		newArray->before = array;
	}
}

void SCORE::ArrayInit(ST_SCORE* newOne) {	//ST_SCOREの初期化
	newOne->score = 0;
	newOne->before = NULL;
	newOne->next = NULL;
}

void SCORE::RankUpdate() {	//ランキングを表示する
	int num = CountArray();
	MoveFirst();
	
	for (int e = 0, add = 0; e < num; e++,add++) {
		font(add + 1, U"位").drawAt(RANK_X, 50 + STANDARD * add);
		if (array->score == NULL) {
			font(0).drawAt(SCORE_X, 50+STANDARD * add);
		}
		else {
			font(array->score).drawAt(SCORE_X, 50+STANDARD * add);
		}
		if (array->next != NULL) {
			array = array->next;
		}
	}
}
