#include "BlockCreate.h"
#include "Block.h"
#include "../ImGui/imgui.h"

BlockCreate::BlockCreate()
{
	blockStage = 3;
	Create();

}

BlockCreate::~BlockCreate()
{
}

void BlockCreate::Update()
{
	if (CheckHitKey(VK_LBUTTON)) {

	}
}

void BlockCreate::Draw()
{
}

void BlockCreate::Create()
{
	//ブロック3x3を生成
	int num = 0;
	for (int x = 0; x < blockStage; x++) {
		for (int y = blockStage-1; y >= 0; y--) {
			//8個生成する
			if (num >= 8) {
				blockArray[y][x] = nullptr;
				return;
			}

			Block* block = Instantiate<Block>();
			block->SetPosition(VGet(x * 100 - 100, y * 100 - 100, 0.0f));
			GetMousePos();
			block->CollLine(startPos, endPos);
			//collLineがtrueだったら隣がnullか確認して動かす
			//falseだったら何もしない

			//確認入れる
			blockArray[y][x] = block;
			num += 1;
		}
	}
}

void BlockCreate::GetMousePos()
{
	//マウスの当たり判定
	GetMousePoint(&mouseX, &mouseY);
	startPos = ConvScreenPosToWorldPos(VGet(mouseX, mouseY, 0.0f));
	endPos = ConvScreenPosToWorldPos(VGet(mouseX, mouseY, 1.0f));
}
