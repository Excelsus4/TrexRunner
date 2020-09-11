#include "stdafx.h"
#include "Trex.h"

Trex::Trex(wstring shaderFile, wstring textureFile):
Rect(shaderFile, textureFile), velocity(0.0f), gravity(-1.0f), strength(0.25f), bOnGround(true)
{
}

Trex::~Trex()
{
}

void Trex::Update()
{
	__super::Update();
	D3DXVECTOR2 position = Position();
	velocity += gravity * Time::Delta();

	if (bOnGround == false) {
		position.y += velocity;
		Position(position);
	}
	if (position.y < Scale().y*0.5f + (Height / 2 - 12)) {
		position.y = Scale().y*0.5f + (Height / 2 - 12);
		velocity = 0.0f;

		bOnGround = true;

		Position(position);
	}
}

void Trex::StartJump()
{
	if (bOnGround == true) {
		velocity = strength;
		bOnGround = false;
	}
}

void Trex::EndJump()
{
	if (velocity > strength / 3)
		velocity = strength / 3;
}

bool Trex::CollisionCheck(const Rect & target)
{
	D3DXVECTOR2 spos = Position();
	D3DXVECTOR2 sscl = Scale();
	D3DXVECTOR2 tpos = target.Position();
	D3DXVECTOR2 tscl = target.Scale();

	int frame = 3;
	if (spos.x + sscl.x / 2-frame > tpos.x - tscl.x / 2+ frame &&
		spos.x - sscl.x / 2+ frame < tpos.x + tscl.x / 2- frame &&
		spos.y + sscl.y / 2- frame > tpos.y - tscl.y / 2+ frame &&
		spos.y - sscl.y / 2+ frame < tpos.y + tscl.y / 2- frame) {
		return true;
	}
	return false;
}
