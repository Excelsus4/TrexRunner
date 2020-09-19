#pragma once
#include "GameObject.h"

class Cactus : GameObject
{
public:
	Cactus(wstring shaderFile, wstring textureFile, D3DXVECTOR2 p, D3DXVECTOR2 s, float* sFactor);
	virtual ~Cactus();

	virtual void Update(D3DXMATRIX& V, D3DXMATRIX& P) override;
	virtual void Render() override;

private:
	Sprite* sprite;
	float* speed;
};

