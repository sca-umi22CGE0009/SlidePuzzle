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
	//�u���b�N3x3�𐶐�
	for (int x = 0; x < blockStage; x++) {
		for (int y = blockStage; y > 0; y--) {
			//�X�ڂ𐶐�����O�ɏI���
			if (x == blockStage - 1 && y == 1) {
				blockArray[y][x] = nullptr;
				return;
			}

			Block* block = Instantiate<Block>();
			if (block != nullptr) {
				//�V���b�t�������z��(����)������
				block->SetPosition(VGet(x * 100 - 100, y * 100 - 200, 0.0f));

				//�m�F�����
				blockArray[y][x] = block;
			}
		}
	}
}
