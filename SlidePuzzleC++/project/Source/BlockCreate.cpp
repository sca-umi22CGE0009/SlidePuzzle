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
			block->CollLine(startPos, endPos);
			//collLine��true��������ׂ�null���m�F���ē�����
			//false�������牽�����Ȃ�

			//�m�F�����
			blockArray[y][x] = block;
			num += 1;
		}
	}
}

void BlockCreate::GetMousePos()
{
	//�}�E�X�̓����蔻��
	GetMousePoint(&mouseX, &mouseY);
	startPos = ConvScreenPosToWorldPos(VGet(mouseX, mouseY, 0.0f));
	endPos = ConvScreenPosToWorldPos(VGet(mouseX, mouseY, 1.0f));
}
