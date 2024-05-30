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

}

void BlockCreate::Create()
{
	//ブロック3x3を生成
	int num = 0;
	for (int x = 0; x < blockStage; x++) {
		for (int y = blockStage-1; y >= 0; y--) {
			//９個目を生成する前に終わる
			if (num >= 8) {
				blockArray[y][x] = nullptr;
				return;
			}

			Block* block = Instantiate<Block>();
			//シャッフルした配列(数字)を入れる
			block->SetPosition(VGet(x * 100 - 100, y * 100 - 100, 0.0f));

			//確認入れる
			blockArray[y][x] = block;
			num += 1;
		}
	}
}
