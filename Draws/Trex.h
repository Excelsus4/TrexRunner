#pragma once
#include "Draws/Rect.h"

class Trex:
	public Rect
{
public:
	Trex(wstring shaderFile, wstring textureFile);
	virtual ~Trex();

	virtual void Update() override;

	void StartJump();
	void EndJump();

	bool CollisionCheck(const Rect& target);

private:
	float velocity;
	float strength;
	float gravity;
	bool bOnGround;
};