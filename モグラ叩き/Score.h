#pragma once

#define FILE_MAX	(10)

struct ST_SCORE {
	int score;
	ST_SCORE* before;
	ST_SCORE* next;
};

class SCORE {
	ST_SCORE* array;	//スコアを記録する
	ST_SCORE* s_array;	//ポインタ保存
	int gameScore;
	FILE* save_file;
	const Font font{ 32 };
	char file_name[13] = "SaveFile.bin";

public:
	SCORE();	//コンストラクタ
	~SCORE();	//デストラクタ
	void SaveData();	//セーブ
	void LoadSave();	//ロード
	void Init();	//初期化
	void Uninit();	//抜ける処理
	void SetScore();	//敵を倒したときにscoreを増やす
	int GetScore();	//scoreのゲッター
	void MakeFirstArray();	//最初の要素を作る
	ST_SCORE* MakeArray();	//要素を追加する
	void MoveFirst();	//要素の一番最初へ移動する
	void MoveLast();	//要素の最後へ移動する
	int CountArray();	//要素の数を数える
	void ScoreIn();	//要素にスコアを入れる
	void ArrayInit(ST_SCORE* newOne);	//ST_SCOREの初期化
	void RemoveArray(ST_SCORE* removed);	//削除する
	void RankUpdate();	//ランキングを表示する
};
