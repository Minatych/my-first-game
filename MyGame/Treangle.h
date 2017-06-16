#pragma once
#include "Renderer.h"

class Treangle
{
public:
	Treangle(Renderer& renderer);
	void Draw(Renderer& renderer);
	~Treangle();
private:
	ID3D11Buffer* vertexBuffer = nullptr;
};

