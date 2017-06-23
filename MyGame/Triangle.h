#pragma once
#include "Renderer.h"

class Triangle
{
public:
	Triangle(Renderer& renderer);
	void Draw(Renderer& renderer);
	~Triangle();
private:
	void CreateMesh(Renderer& renderer);
	void CreateShaders(Renderer& renderer);

	ID3D11Buffer* vertexBuffer = nullptr;
	ID3D11VertexShader* vertexShader = nullptr;
	ID3D11PixelShader* pixelShader = nullptr;
	ID3D11InputLayout* inputLayOut = nullptr;
};

