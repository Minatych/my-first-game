#include "Treangle.h"
#include <fstream>
#include <vector>


struct Vertex {
	float x, y;
	float r, g, b;
};

Treangle::Treangle(Renderer & renderer)
{
	CreateMesh(renderer);
	CreateShaders(renderer);
}

void Treangle::Draw(Renderer & renderer)
{
	// Bind iur triangle shaders
	renderer.getDeviceContext()->VSSetShader(vertexShader, nullptr, 0);
	renderer.getDeviceContext()->PSSetShader(pixelShader, nullptr, 0);

	// Bind our vertex buffer
	UINT stride = sizeof(Vertex);
	UINT offset = 0;
	renderer.getDeviceContext()->IASetVertexBuffers(0, 1, &vertexBuffer, &stride, &offset);//Input Assembler

	// Draw
	renderer.getDeviceContext()->Draw(3, 0);
}

Treangle::~Treangle()
{
	vertexBuffer->Release();
	vertexShader->Release();
	pixelShader->Release();
}

void Treangle::CreateMesh(Renderer & renderer)
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

void Treangle::CreateShaders(Renderer & renderer)
{
	std::ifstream vsFile("triangleVertexShader.cso", std::ios::binary);
	std::ifstream psFile("trianglePixelShader.cso", std::ios::binary);

	std::vector<char> vsData = {std::istreambuf_iterator<char>(vsFile), std::istreambuf_iterator<char>()};
	std::vector<char> psData = {std::istreambuf_iterator<char>(psFile), std::istreambuf_iterator<char>() };

	renderer.getDevice()->CreateVertexShader(vsData.data(), vsData.size(), nullptr, &vertexShader);
	renderer.getDevice()->CreatePixelShader(psData.data(), psData.size(), nullptr, &pixelShader);
}
