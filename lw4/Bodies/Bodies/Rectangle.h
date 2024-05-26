#pragma once
#include "Point.h"
#include "ISolidShape.h"

class MyRectangle : public ISolidShape
{
public:
	MyRectangle(Point, Point, uint32_t = 0, uint32_t = 0);
	MyRectangle(double, double, double, double, uint32_t = 0, uint32_t = 0);
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	uint32_t GetOutlineColor() const override;
	uint32_t GetFillColor() const override;

	Point GetLeftTop();
	Point GetRightBottom();
	double GetWidth() const;
	double GetHeight() const;

private:
	Point m_vertex1, m_vertex2;
	uint32_t m_outlineColor, m_fillColor;
};