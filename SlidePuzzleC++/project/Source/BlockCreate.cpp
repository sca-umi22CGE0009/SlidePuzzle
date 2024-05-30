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
	int num = 0;
	for (int x = 0; x < blockStage; x++) {
		for (int y = blockStage-1; y >= 0; y--) {
			//�X�ڂ𐶐�����O�ɏI���
			if (num >= 8) {
				blockArray[y][x] = nullptr;
				return;
			}

			Block* block = Instantiate<Block>();
			//�V���b�t�������z��(����)������
			block->SetPosition(VGet(x * 100 - 100, y * 100 - 100, 0.0f));

			//�m�F�����
			blockArray[y][x] = block;
			num += 1;
		}
	}
}
