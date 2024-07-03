#include "Block.h"
#include <Vector>

Block::Block()
{
	hModel = MV1LoadModel("data/block/block.mv1");
	position = VGet(0, 0, 100);
	rotation = VGet(DX_PI_F / 2, 0, 0);
}

Block::~Block()
{
}

void Block::Update()
{
}

void Block::Draw()
{
	//���f���ǂݍ���
	MV1SetPosition(hModel, position);
	MV1SetRotationXYZ(hModel, rotation);
	MV1DrawModel(hModel);
}

void Block::SetPosition(VECTOR pos)
{
	position = pos;
}

//�}�E�X�N���b�N�m�F
bool Block::CollLine(VECTOR p1, VECTOR p2, VECTOR* hitPos)
{
	MV1RefreshCollInfo(hModel, -1);

	MV1_COLL_RESULT_POLY res =
		MV1CollCheck_Line(hModel, -1, p1, p2);
	if (res.HitFlag) // �������Ă���
	{
		if (hitPos != nullptr)
		{
			*hitPos = res.HitPosition; // �����������W��������
		}
		return true;
	}
	return false;
}
