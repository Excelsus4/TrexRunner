#pragma once
#include "ShiftingObject.h"

class Cactus :
	public ShiftingObject
{
public:
	Cactus(wstring shaderFile, wstring textureFile);
	virtual ~Cactus();

	virtual void Update() override;
};

