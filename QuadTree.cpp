#include "QuadTree.h"

QuadTree::QuadTree(std::shared_ptr<Boundary> boundary, int n)
{
	this->boundary = *boundary;
	this->capacity = n;
}

void QuadTree::Subdivide()
{
	int x = this->boundary.x;
	int y = this->boundary.y;
	int w = this->boundary.w;
	int h = this->boundary.h;

	std::shared_ptr<Boundary> ne = std::make_unique<Boundary>(x + w / 2, y - h / 2, w / 2, h / 2);
	this->northeast = std::make_unique<QuadTree>(ne, this->capacity);
	std::shared_ptr<Boundary> nw = std::make_unique<Boundary>(x - w / 2, y - h / 2, w / 2, h / 2);
	this->northwest = std::make_unique<QuadTree>(nw, this->capacity);
	std::shared_ptr<Boundary> se = std::make_unique<Boundary>(x + w / 2, y + h / 2, w / 2, h / 2);
	this->southeast = std::make_unique<QuadTree>(se, this->capacity);
	std::shared_ptr<Boundary> sw = std::make_unique<Boundary>(x - w / 2, y + h / 2, w / 2, h / 2);
	this->southwest = std::make_unique<QuadTree>(sw, this->capacity);

	this->divided = true;
}

void QuadTree::Insert(Point& p)
{
	if (!this->boundary.Contains(p))
	{
		return;
	}

	if (this->points.size() < this->capacity)
	{
		this->points.push_back(p);
	}
	else
	{
		if (!this->divided)
		{
			this->Subdivide();
			
		}
		this->northeast->Insert(p);
		this->northwest->Insert(p);
		this->southeast->Insert(p);
		this->southwest->Insert(p);
	}
}