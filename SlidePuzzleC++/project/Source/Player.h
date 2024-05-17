#pragma once
//Player.h
#include "../Library/gameObject.h"

class Player : public GameObject {
public:
	Player();
	~Player();
	void Update() override;
	void Draw() override;
private:
	VECTOR start3DPos;
	VECTOR end3DPos;
	VECTOR screenPos;
	int MouseX, MouseY;
};