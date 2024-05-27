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
	static const int blockStage = 3;
	Block* blockArray[blockStage][blockStage];

	void Create();
	//ƒVƒƒƒbƒtƒ‹‚ÌŠÖ”
};
