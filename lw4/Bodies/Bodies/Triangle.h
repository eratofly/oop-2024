#pragma once
#include "ISolidShape.h"
#include "Point.h"
class Triangle : public ISolidShape
{
public:
	Triangle(Point, Point, Point, uint32_t = 0, uint32_t = 0);
	Triangle(double, double, double, double, double, double, uint32_t = 0, uint32_t = 0);
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	uint32_t GetOutlineColor() const override;
	uint32_t GetFillColor() const override;

	Point GetVertex1();
	Point GetVertex2();
	Point GetVertex3();

private:
	Point m_vertex1, m_vertex2, m_vertex3;
	uint32_t m_outlineColor, m_fillColor;
};
