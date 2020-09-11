#include "stdafx.h"
#include "GameObject.h"

GameObject::GameObject(wstring shaderFile, wstring textureFile):
	Rect(shaderFile, textureFile), velocity(0.0f), gravity(-1.0f), strength(0.25f), bOnGround(true)
{
}

GameObject::~GameObject()
{
}

void GameObject::Update()
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

void GameObject::MoveLeft()
{
	D3DXVECTOR2 position = Position();
	position.x -= (*speed)* Time::Delta();

	Position(position);
}

void GameObject::StartJump()
{
	if (bOnGround == true) {
		velocity = strength;
		bOnGround = false;
	}
}

void GameObject::EndJump()
{
	if (velocity > strength / 3)
		velocity = strength / 3;
}

bool GameObject::CollisionCheck(const Rect & target)
{
	D3DXVECTOR2 spos = Position();
	D3DXVECTOR2 sscl = Scale();
	D3DXVECTOR2 tpos = target.Position();
	D3DXVECTOR2 tscl = target.Scale();

	if (spos.x + sscl.x / 2 > tpos.x - tscl.x / 2 &&
		spos.x - sscl.x / 2 < tpos.x + tscl.x / 2 &&
		spos.y + sscl.y / 2 > tpos.y - tscl.y / 2 &&
		spos.y - sscl.y / 2 < tpos.y + tscl.y / 2) {
		return true;
	}
	return false;
}
