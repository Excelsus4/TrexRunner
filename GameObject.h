#pragma once
#include "Draws/Rect.h"
class GameObject :
	public Rect
{
public:
	GameObject(wstring shaderFile, wstring textureFile);
	virtual ~GameObject();

	virtual void Update() override;

	void MoveLeft();

	void Speed(float* fpS) { speed = fpS; }

	void StartJump();
	void EndJump();

	bool CollisionCheck(const Rect& target);
private:
	float* speed;

	float velocity;
	float strength;
	float gravity;
	bool bOnGround;
};

