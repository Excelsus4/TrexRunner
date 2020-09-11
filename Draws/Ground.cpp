#include "stdafx.h"
#include "Ground.h"

Ground::Ground(wstring shaderFile, wstring textureFile):
	ShiftingObject(shaderFile, textureFile)
{
}

Ground::~Ground()
{
}

void Ground::Update()
{
	__super::Update();
	//When ground is out of place, return cartridge
	D3DXVECTOR2 pos = Position();
	D3DXVECTOR2 scl = Scale();

	if (pos.x < scl.x / 2-1200) {
		pos.x += 2400;
		Position(pos);
	}
}
