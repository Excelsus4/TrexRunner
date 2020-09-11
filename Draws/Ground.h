#pragma once
#include "ShiftingObject.h"

class Ground:
	public ShiftingObject
{
public:
	Ground(wstring shaderFile, wstring textureFile);
	virtual ~Ground();

	virtual void Update() override;
};

