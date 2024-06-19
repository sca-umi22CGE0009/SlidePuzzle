#include "BlockCreate.h"

BlockCreate::BlockCreate()
{
	Create();
}

BlockCreate::~BlockCreate()
{
}

void BlockCreate::Update()
{
}

void BlockCreate::Draw()
{
	DrawFormatString(0, 100, GetColor(255,255,255), "座標Ｘ %d　　座標Ｙ %d", mouseX, mouseY);
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
			block->CollLine(StartPos, EndPos);

			//確認入れる
			blockArray[y][x] = block;
			num += 1;
		}
	}
}

void BlockCreate::GetMousePos()
{
	GetMousePoint(&mouseX, &mouseY);
	StartPos = ConvScreenPosToWorldPos(VGet(mouseX, mouseY, 0.0f));
	EndPos = ConvScreenPosToWorldPos(VGet(mouseX, mouseY, 1.0f));

	// モデルと線分との当たり判定
	//モデルの変数を別のクラスに持ってくる方法
}
