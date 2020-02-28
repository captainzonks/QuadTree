#pragma once

#include "Point.h"

class Boundary
{
private:

public:
	Boundary();
	Boundary(int x, int y, int w, int h);
	int x{};
	int y{};
	int w{};
	int h{};

	bool Contains(Point& point);
};

