#include "Player.h"
#include <vector>;


Player::Player()
{

}

Player::~Player()
{
}

void Player::Update()
{
	GetMousePoint(&MouseX, &MouseY);
	screenPos.x = (float)MouseX;
	screenPos.y = (float)MouseY;
	screenPos.z = 0.0f;

	start3DPos = ConvScreenPosToWorldPos(screenPos);
	screenPos.z = 1.0f;
	end3DPos = ConvScreenPosToWorldPos(screenPos);
}

void Player::Draw()
{
}
