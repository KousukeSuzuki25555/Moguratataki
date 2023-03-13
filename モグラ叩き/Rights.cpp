#include "Rights.h"

void RIGHT::Update() {
	font(U"使用ライブラリー:Siv3D(press F1)").drawAt(640, 240);
	font(U"BGM,SE:魔王魂").drawAt(640, 360);
	if (KeyF1.down())
	{
		// ライセンス情報を表示
		LicenseManager::ShowInBrowser();
	}
}
