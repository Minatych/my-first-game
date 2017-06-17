#pragma once

class Point2D
{
public:
	Point2D();
	Point2D(int x, int y);
	~Point2D();
	
	int GetX();
	int GetY();
	void SetX(int);
	void SetY(int);
private:
	int x;
	int y;
};