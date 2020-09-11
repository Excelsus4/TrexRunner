#include "stdafx.h"
#include "ShiftingObject.h"

ShiftingObject::ShiftingObject(wstring shaderFile, wstring textureFile):
	Rect(shaderFile, textureFile)
{
}

ShiftingObject::~ShiftingObject()
{
}

void ShiftingObject::Update()
{
	__super::Update();
}

void ShiftingObject::MoveLeft()
{
	D3DXVECTOR2 position = Position();
	position.x -= (*speed)* Time::Delta();

	Position(position);
}
