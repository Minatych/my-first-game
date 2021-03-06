#include "Triangle.h"
#include <fstream>
#include <vector>


struct Vertex {
	float x, y;
	float r, g, b;
};

Triangle::Triangle(Renderer & renderer)
{
	CreateMesh(renderer);
	CreateShaders(renderer);
}

void Triangle::Draw(Renderer & renderer)
{
	auto deviceContext = renderer.getDeviceContext();
	// Bind iur triangle shaders
	deviceContext->IASetInputLayout(inputLayOut);
	deviceContext->VSSetShader(vertexShader, nullptr, 0);
	deviceContext->PSSetShader(pixelShader, nullptr, 0);

	// Bind our vertex buffer
	UINT stride = sizeof(Vertex);
	UINT offset = 0;
	deviceContext->IASetVertexBuffers(0, 1, &vertexBuffer, &stride, &offset);//Input Assembler

	// Draw
	deviceContext->Draw(3, 0);
}

Triangle::~Triangle()
{
	vertexBuffer->Release();
	vertexShader->Release();
	pixelShader->Release();
	inputLayOut->Release();
}

void Triangle::CreateMesh(Renderer & renderer)
{
	// Define our vertices
	Vertex vertices[] =
	{
		{ -1,-1, 1, 0, 0 },
		{ 0, 1, 0, 1, 0 },
		{ 1,-1, 0, 0, 1 },
	};

	// Create our vertex buffer
	auto vertexBufferDesc = CD3D11_BUFFER_DESC(sizeof(vertices), D3D11_BIND_VERTEX_BUFFER);
	D3D11_SUBRESOURCE_DATA vertexData = { 0 };
	vertexData.pSysMem = vertices;

	renderer.getDevice()->CreateBuffer(&vertexBufferDesc, &vertexData, &vertexBuffer);
}

void Triangle::CreateShaders(Renderer & renderer)
{

	std::ifstream vsFile("triangleVertexShader.cso", std::ios::binary);
	std::ifstream psFile("trianglePixelShader.cso", std::ios::binary);

	std::vector<char> vsData = {std::istreambuf_iterator<char>(vsFile), std::istreambuf_iterator<char>()};
	std::vector<char> psData = {std::istreambuf_iterator<char>(psFile), std::istreambuf_iterator<char>() };

	renderer.getDevice()->CreateVertexShader(vsData.data(), vsData.size(), nullptr, &vertexShader);
	renderer.getDevice()->CreatePixelShader(psData.data(), psData.size(), nullptr, &pixelShader);

	// Create input layout
	D3D11_INPUT_ELEMENT_DESC layout[] = 
	{
		{"POSITION", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0},
		{"COLOR", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 }
	};
	renderer.getDevice()->CreateInputLayout(layout, 2, vsData.data(), vsData.size(), &inputLayOut);
}
