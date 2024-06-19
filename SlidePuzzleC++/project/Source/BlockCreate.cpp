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
	DrawFormatString(0, 100, GetColor(255,255,255), "���W�w %d�@�@���W�x %d", mouseX, mouseY);
}

void BlockCreate::Create()
{
	//�u���b�N3x3�𐶐�
	int num = 0;
	for (int x = 0; x < blockStage; x++) {
		for (int y = blockStage-1; y >= 0; y--) {
			//8��������
			if (num >= 8) {
				blockArray[y][x] = nullptr;
				return;
			}

			Block* block = Instantiate<Block>();
			block->SetPosition(VGet(x * 100 - 100, y * 100 - 100, 0.0f));
			GetMousePos();
			block->CollLine(StartPos, EndPos);

			//�m�F�����
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

	// ���f���Ɛ����Ƃ̓����蔻��
	//���f���̕ϐ���ʂ̃N���X�Ɏ����Ă�����@
}
