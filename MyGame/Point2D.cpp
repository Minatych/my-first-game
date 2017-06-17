#include "Point2D.h"

Point2D::Point2D()
{
}

Point2D::Point2D(int x, int y)
{
	this->x = x;
	this->y = y;
}

Point2D::~Point2D()
{
}

int Point2D::GetX()
{
	return x;
}

int Point2D::GetY()
{
	return y;
}

void Point2D::SetX(int value)
{
	x = value;
}

void Point2D::SetY(int value)
{
	y = value;
}
