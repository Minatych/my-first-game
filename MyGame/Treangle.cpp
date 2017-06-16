#include "Treangle.h"

struct Vertex {
	float x, y;
	float r, g, b;
};

Treangle::Treangle(Renderer & renderer)
{
	// Define our vertices
	Vertex vertices[] = 
	{
		{-1,-1, 1, 0, 0 },
		{ 0, 1, 0, 1, 0 },
		{ 1,-1, 0, 0, 1 },
	};

	// Create our vertex buffer
	auto vertexBufferDesc = CD3D11_BUFFER_DESC(sizeof(vertices), D3D11_BIND_VERTEX_BUFFER);
	D3D11_SUBRESOURCE_DATA vertexData = { 0 };
	vertexData.pSysMem = vertices;

	renderer.getDevice()->CreateBuffer(&vertexBufferDesc, &vertexData, &vertexBuffer);
}

void Treangle::Draw(Renderer & renderer)
{
	// Bind our vertex buffer
	UINT stride = sizeof(Vertex);
	UINT offset = 0;
	renderer.getDeviceContext()->IASetVertexBuffers(0, 1, &vertexBuffer, &stride, &offset);//Input Assembler

	// Draw
	//renderer.getDeviceContext()->Draw(3, 0);
}

Treangle::~Treangle()
{
}
