#include "BlockCreate.h"
#include "Block.h"

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
	for (int x = 0; x < blockStage; x++) {
		for (int y = blockStage; y > 0; y--) {
			if (x == blockStage - 1 && y == 1) {
				//９個目を生成する前に終わる
				return;
			}
			Block* block = Instantiate<Block>();
			//シャッフルした配列(数字)を入れる
			block->SetPosition(VGet(x * 100 - 100, y * 100 - 100, 0));
		}
	}
}
