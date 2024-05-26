#pragma once
#include "Point.h"
#include "ISolidShape.h"

class Circle : public ISolidShape
{
public:
	Circle(Point, double, uint32_t = 0, uint32_t = 0);
	Circle(double, double, double, uint32_t = 0, uint32_t = 0);
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	uint32_t GetOutlineColor() const;
	uint32_t GetFillColor() const override;

	Point GetCenter();
	double GetRadius() const;

private:
	Point m_center;
	double m_radius;
	uint32_t m_outlineColor, m_fillColor;
};