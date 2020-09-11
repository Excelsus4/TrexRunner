#include "stdafx.h"
#include "Cactus.h"

Cactus::Cactus(wstring shaderFile, wstring textureFile) :
	ShiftingObject(shaderFile, textureFile)
{
}

Cactus::~Cactus()
{
}

void Cactus::Update()
{
	__super::Update();
	//if the cactus is out of map, randomly return cartridge
	D3DXVECTOR2 pos = Position();
	D3DXVECTOR2 scl = Scale();

	float randomOffset = Math::Random(0.0f, Width);

	if (pos.x < - scl.x / 2) {
		pos.x += Width + scl.x + randomOffset;
		Position(pos);
	}
}
