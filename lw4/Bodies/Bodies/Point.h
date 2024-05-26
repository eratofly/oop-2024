#pragma once
#include <string>

class Point
{
public:
	Point(double, double);
	std::string ToString() const;
	double x, y;

	// вынести за пределы класса
};

double GetDistance(Point, Point);