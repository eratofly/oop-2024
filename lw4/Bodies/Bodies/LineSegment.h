#pragma once
#include "Point.h"
#include "IShape.h"
#include <iostream>

class LineSegment : public IShape
{
public:
	LineSegment(Point, Point, uint32_t = 0);
	LineSegment(double, double, double, double, uint32_t = 0);
	Point GetStartPoint() const;
	Point GetEndPoint() const;
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	uint32_t GetOutlineColor() const override;

private:
	Point m_startPoint, m_endPoint;
	uint32_t m_outlineColor;
};