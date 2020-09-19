#pragma once
#include "GameObject.h"

class Cactus : GameObject
{
public:
	Cactus(wstring shaderFile, wstring textureFile);
	virtual ~Cactus();

	void Update(D3DXMATRIX& V, D3DXMATRIX& P);
	void Render();
};

