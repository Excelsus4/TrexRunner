#include "stdafx.h"
#include "./Systems/Device.h"
#include "./GameObject/Ground.h"
#include "./GameObject/Trex.h"

Trex* character;
vector<Ground*> grounds;
float speed = 350.0f;
float score = 0;

void InitScene() {
	wstring spriteFile = Textures + L"Trex/Sprite.png";
	wstring shaderFile = Shaders + L"008_Sprite.fx";
	{
		grounds.push_back(new Ground(shaderFile, Textures + L"Trex/Floor.png", D3DXVECTOR2(0, Height / 2 - 4), &speed));
		grounds.push_back(new Ground(shaderFile, Textures + L"Trex/Floor.png", D3DXVECTOR2(1200, Height / 2 - 4), &speed));
	}

	{
		character = new Trex(shaderFile, spriteFile, D3DXVECTOR2(52, Height / 2 + 12), speed);
	}
}

void DestroyScene() {
	SAFE_DELETE(character);

	for (auto g : grounds)
		SAFE_DELETE(g);
}

D3DXMATRIX V, P;

void Update() {
	if (Key->Down(VK_SPACE))
		character->StartJump();
	else if (Key->Up(VK_SPACE))
		character->EndJump();

	if (Key->Down(VK_DOWN))
		character->StartCrouch();
	else if (Key->Up(VK_DOWN))
		character->EndCrouch();

	//View
	D3DXVECTOR3 eye(0, 0, -1);
	D3DXVECTOR3 at(0, 0, 0);
	D3DXVECTOR3 up(0, 1, 0);
	D3DXMatrixLookAtLH(&V, &eye, &at, &up);

	//Projection
	D3DXMatrixOrthoOffCenterLH(&P, 0, (float)Width, 0, (float)Height, -1, 1);

	for (auto g : grounds) {
		g->Update(V, P);
	}
	character->Update(V, P);

	score += speed * Time::Delta();
}

void Render() {
	D3DXCOLOR bgColor = D3DXCOLOR(.97f, .97f, .97f, 1);
	DeviceContext->ClearRenderTargetView(RTV, (float*)bgColor);
	{
		ImGui::Text("Score: %.0f", score);
		ImGui::SliderFloat("Speed", &speed, 0.0f, 700.0f);

		for (auto g : grounds) {
			g->Render();
		}
		character->Render();
	}
	ImGui::Render();
	SwapChain->Present(0, 0);
}