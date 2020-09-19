#include "stdafx.h"
#include "Cactus.h"

Cactus::Cactus(wstring shaderFile, wstring textureFile, D3DXVECTOR2 p, D3DXVECTOR2 s, float * sFactor):
	GameObject(p, s), speed(sFactor)
{
	sprite = new Sprite(textureFile, shaderFile);
	sprite->Position(p);
}

Cactus::~Cactus()
{
	SAFE_DELETE(sprite);
}

void Cactus::Update(D3DXMATRIX & V, D3DXMATRIX & P)
{
	// Shift Ground
	D3DXVECTOR2 pos = Position();
	D3DXVECTOR2 scl = Size();
	pos.x -= (*speed)* Time::Delta();

	//TODO: When cactus is out of place, Remove maybe
	Position(pos);

	sprite->Position(Position());
	sprite->Update(V, P);
}

void Cactus::Render()
{
	sprite->Render();
}
