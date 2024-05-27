#include "playScene.h"
#include "../Library/sceneManager.h"
#include "DebugScreen.h"
#include <DxLib.h>
#include "BlockCreate.h"
#include "Player.h"

PlayScene::PlayScene()
{
	//ÉJÉÅÉâÇÃà íu
	SetCameraPositionAndTarget_UpVecY(
				VGet(0,0,-500), VGet(0,0,0));
	SetLightDirection(GetCameraPosition()* -1);
	SetLightDifColor(GetColorF(1.0f, 1.0f, 0.0f, 1.0f));


	Instantiate<BlockCreate>();
	Instantiate<Player>();
}


PlayScene::~PlayScene()
{
}

void PlayScene::Update()
{
	if (CheckHitKey(KEY_INPUT_T)) {
		SceneManager::ChangeScene("TitleScene");
	}
	SceneBase::Update();
}

void PlayScene::Draw()
{
	SceneBase::Draw();

	DrawString(0, 0, "PLAY SCENE", GetColor(255, 255, 255));
	DrawString(100, 400, "Push [T]Key To Title", GetColor(255, 255, 255));
}
