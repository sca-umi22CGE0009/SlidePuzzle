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
private:
	int blockStage = 3;
	Block* blockArray[3][3];

	void Create();
	//ƒVƒƒƒbƒtƒ‹‚ÌŠÖ”
};
