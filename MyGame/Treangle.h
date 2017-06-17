#pragma once
#include "Renderer.h"

class Treangle
{
public:
	Treangle(Renderer& renderer);
	void Draw(Renderer& renderer);
	~Treangle();
private:
	void CreateMesh(Renderer& renderer);
	void CreateShaders(Renderer& renderer);

	ID3D11Buffer* vertexBuffer = nullptr;
	ID3D11VertexShader* vertexShader = nullptr;
	ID3D11PixelShader* pixelShader = nullptr;
	ID3D11InputLayout* inputLayOut = nullptr;
};

