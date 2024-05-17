#pragma once
//Block.h
#include "../Library/gameObject.h"

class Block : public GameObject {
public:
	Block();
	~Block();
	void Update() override;
	void Draw() override;
	void SetPosition(VECTOR pos);
	bool CollLine(VECTOR p1, VECTOR p2, VECTOR* hitPos = nullptr);
private:
	int hModel;
	VECTOR position;
	VECTOR rotation;
};

//�e�N���X�����
//�����ɂX��Instantiate������
//playScene�ɂ��̃N���X��Instantiate����


//int num�Ńi���o�[���������č����Ă�����N���A