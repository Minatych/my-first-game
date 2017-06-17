#include "Renderer.h"
#include <d3d11.h>

Renderer::Renderer(Window & window)
{
	CreateDevice(window);
	CreateRenderTarget();
}

void Renderer::BeginFrame()
{
	// Set the background color!
	float clearColor[] = { .25f, .5f, 1, 1 };
	deviceContext->ClearRenderTargetView(renderTargetView, clearColor);
}

void Renderer::EndFrame()
{
	//Swap buffer
	swapChain->Present(1, 0);
}

ID3D11Device * Renderer::getDevice()
{
	return device;
}

ID3D11DeviceContext * Renderer::getDeviceContext()
{
	return deviceContext;
}

void Renderer::CreateDevice(Window & window)
{
	// Define our swap chain
	DXGI_SWAP_CHAIN_DESC swapChainDesc = { 0 };
	swapChainDesc.BufferCount = 1;//Double buffering
	swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDesc.OutputWindow = window.GetHandle();
	swapChainDesc.SampleDesc.Count = 1;
	swapChainDesc.Windowed = true;

	// Create the swap chain device and context;
	auto result = D3D11CreateDeviceAndSwapChain(
		nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, 0,
		nullptr, 0, D3D11_SDK_VERSION, &swapChainDesc,
		&swapChain, &device, nullptr, &deviceContext);

	// Check for errors
	if (result != S_OK)
	{
		MessageBox(nullptr, "Problem creating DX11", "Error", MB_OK);
		exit(-1);
	}
}

void Renderer::CreateRenderTarget()
{
	ID3D11Texture2D* backBuffer;
	swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&backBuffer);
	device->CreateRenderTargetView(backBuffer, nullptr, &renderTargetView);
	backBuffer->Release();
}

