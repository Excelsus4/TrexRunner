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
}
