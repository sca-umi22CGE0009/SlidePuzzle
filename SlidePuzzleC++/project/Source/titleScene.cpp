#include "titleScene.h"
#include "../Library/sceneManager.h"
#include "DebugScreen.h"
#include "../ImGui/imgui_impl_dxlib.hpp"

namespace {
	struct Circle
	{
		Circle() {}
		Circle(float _x , float _y , float _r) 
			: x{ _x}
			, y{ _y}
			, r{ _r} {}
		float x = 700, y = 500;
		float r = 5;
		ImVec4 clear_color = ImVec4(1.00f, 0.f, 0.f, 1.00f);
			void Draw() {
			unsigned int color = GetColor(255 * clear_color.x, 255 * clear_color.y, 255 * clear_color.z);
			DrawCircle(x, y, r, color);
		}
	};
	Circle cir1;
	Circle cir2(900,600,10);
	Circle cir3(500,200,50);
}

TitleScene::TitleScene()
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Update()
{
	//çXêV
	if (CheckHitKey(KEY_INPUT_P)) {
		SceneManager::ChangeScene("PlayScene");
	}

	SceneBase::Update();
}


void TitleScene::Draw()
{
	SceneBase::Draw();
	DrawString(0, 0, "TITLE SCENE", GetColor(255,255,255));
	DrawString(100, 400, "Push [P]Key To Play", GetColor(255, 255, 255));
}
