#pragma once
//BlockCreate.h
#include "../Library/gameObject.h"
#include "Block.h"

class BlockCreate : public GameObject {
public:
	BlockCreate();
	~BlockCreate();
	void Update() override;
	void Draw() override;

	void GetMousePos();
private:
	int blockStage = 3;
	Block* blockArray[3][3];

	void Create();
	int mouseX, mouseY;
	VECTOR StartPos, EndPos;
	MV1_COLL_RESULT_POLY hitPoly;
	//ƒVƒƒƒbƒtƒ‹‚ÌŠÖ”
};
