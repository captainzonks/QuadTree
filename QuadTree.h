#pragma once

#include "Boundary.h"
#include "Point.h"

#include <vector>
#include <memory>

class QuadTree
{
private:

public:
	QuadTree(std::shared_ptr<Boundary> boundary, int n);
	void Insert(Point& p);
	void Subdivide();
	Boundary boundary;
	unsigned int capacity{};
	std::vector<Point> points;
	std::shared_ptr<QuadTree> northwest;
	std::shared_ptr<QuadTree> northeast;
	std::shared_ptr<QuadTree> southwest;
	std::shared_ptr<QuadTree> southeast;
	bool divided = false;
};

