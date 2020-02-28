#include "Boundary.h"

Boundary::Boundary()
{
}

Boundary::Boundary(int x, int y, int w, int h)
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
}

bool Boundary::Contains(Point& point)
{
	return (point.x > this->x - this->w &&
		point.x < this->x + this->w &&
		point.y > this->x - this->h &&
		point.y < this->y + this->h);
}