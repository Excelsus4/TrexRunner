#pragma once
#include "Rect.h"
class ShiftingObject :
	public Rect
{
public:
	ShiftingObject(wstring shaderFile, wstring textureFile);
	virtual ~ShiftingObject();

	virtual void Update() override;

	void MoveLeft();

	void Speed(float* fpS) { speed = fpS; }
private:
	float* speed;
};

