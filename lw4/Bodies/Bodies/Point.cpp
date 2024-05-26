#include "Point.h"
#include <string>

Point::Point(double x, double y)
	: x(x)
	, y(y)
{
}

double GetDistance(Point p1, Point p2)
{
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

std::string Point::ToString() const
{
	return "(" + std::to_string(x) + ", " + std::to_string(y) + ')';
}