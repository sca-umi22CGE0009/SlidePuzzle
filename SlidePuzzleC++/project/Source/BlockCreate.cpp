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
	for (int x = 0; x < blockStage; x++) {
		for (int y = blockStage; y > 0; y--) {
			//９個目を生成する前に終わる
			if (x == blockStage - 1 && y == 1) {
				blockArray[y][x] = nullptr;
				return;
			}

			Block* block = Instantiate<Block>();
			if (block != nullptr) {
				//シャッフルした配列(数字)を入れる
				block->SetPosition(VGet(x * 100 - 100, y * 100 - 200, 0.0f));

				//確認入れる
				blockArray[y][x] = block;
			}
		}
	}
}
