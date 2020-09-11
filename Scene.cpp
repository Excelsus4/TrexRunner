#include "stdafx.h"
#include "./Systems/Device.h"
#include "./Draws/Trex.h"
#include "./Draws/Ground.h"
#include "./Draws/Cactus.h"

Trex* trex;
vector<Cactus*> cactus;
vector<Ground*> ground;
float speed = 150.0f;
float score = 0;

void InitScene() {
	{
		trex = new Trex(L"../_Shaders/007_Texture.fx", L"../_Textures/Trex/Trex.png");
		trex->Scale(44, 47);

		float x = trex->Scale().x * 0.5f + 30;
		float y = trex->Scale().y * 0.5f + (Height / 2 - 12);
		trex->Position(x, y);
	}

	{
		Cactus* ctemp = new Cactus(L"../_Shaders/007_Texture.fx", L"../_Textures/Trex/Cactus1.png");
		ctemp->Scale(17, 35);

		float x = ctemp->Scale().x * 0.5f + 400;
		float y = ctemp->Scale().y * 0.5f + (Height / 2 - 12);
		ctemp->Position(x, y);

		ctemp->Speed(&speed);

		cactus.push_back(ctemp);
	}

	{
		Ground* f = new Ground(L"../_Shaders/007_Texture.fx", L"../_Textures/Trex/Floor.png");
		f->Scale(1200, 12);

		float x = 0;
		float y = Height / 2-4;
		f->Position(x, y);
		f->Speed(&speed);

		ground.push_back(f);

		f = new Ground(L"../_Shaders/007_Texture.fx", L"../_Textures/Trex/Floor.png");
		f->Scale(1200, 12);

		x = 1200;
		f->Position(x, y);
		f->Speed(&speed);

		ground.push_back(f);
	}
}

void DestroyScene() {
	for (auto c : cactus) {
		delete c;
	}
	for (auto g : ground) {
		delete g;
	}

	SAFE_DELETE(trex);
}

D3DXMATRIX V, P;

void Update() {
	if (Key->Down(VK_SPACE))
		trex->StartJump();
	else if (Key->Up(VK_SPACE))
		trex->EndJump();

	//View
	D3DXVECTOR3 eye(0, 0, -1);
	D3DXVECTOR3 at(0, 0, 0);
	D3DXVECTOR3 up(0, 1, 0);
	D3DXMatrixLookAtLH(&V, &eye, &at, &up);

	//Projection
	D3DXMatrixOrthoOffCenterLH(&P, 0, (float)Width, 0, (float)Height, -1, 1);

	trex->ViewProjection(V, P);
	trex->Update();

	for (auto c : cactus) {
		c->MoveLeft();
		c->ViewProjection(V, P);
		c->Update();
	}
	for (auto g : ground) {
		g->MoveLeft();
		g->ViewProjection(V, P);
		g->Update();
	}
}


void Render() {
	D3DXCOLOR bgColor = D3DXCOLOR(.97f, .97f, .97f, 1);
	DeviceContext->ClearRenderTargetView(RTV, (float*)bgColor);
	{
		ImGui::Text("Score: %d", score);
		ImGui::SliderFloat("Speed", &speed, 0.0f, 400.0f);

		for (auto g : ground) {
			g->Render();
		}
		for (auto c : cactus) {
			c->Render();
		}
		trex->Render();

	}
	ImGui::Render();
	SwapChain->Present(0, 0);
}