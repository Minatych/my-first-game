#pragma once
#include "Window.h"
#include <d3d11.h> 

class Renderer
{
public:
	Renderer(Window& window);

private:
	IDXGISwapChain* swapChain = nullptr;
	ID3D11Device* device = nullptr;
	ID3D11DeviceContext* deviceContext = nullptr;
};