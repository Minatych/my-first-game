#pragma once
#include "Window.h"
#include <d3d11.h> 

class Renderer
{
public:
	Renderer(Window& window);
	void BeginFrame();
	void EndFrame();

	ID3D11Device* getDevice();
	ID3D11DeviceContext* getDeviceContext();
private:
	void CreateDevice(Window& window);
	void CreateRenderTarget();

	// Device stuff
	IDXGISwapChain* swapChain = nullptr;
	ID3D11Device* device = nullptr;
	ID3D11DeviceContext* deviceContext = nullptr;

	// Render target
	ID3D11RenderTargetView* renderTargetView = nullptr;
	D3D11_TEXTURE2D_DESC backBufferDesc;
};