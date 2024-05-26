#define _USE_MATH_DEFINES
#include "Circle.h"
#include <cmath>
#include <sstream>
#include <string>

using namespace std;

Circle::Circle(Point center, double radius, uint32_t outlineColor, uint32_t fillColor)
	: m_center(center)
	, m_radius(radius)
	, m_outlineColor(outlineColor)
	, m_fillColor(fillColor)
{
}

Circle::Circle(double x, double y, double r, uint32_t outlineColor, uint32_t fillColor)
	: Circle(Point(x, y), r, outlineColor, fillColor)
{
}

Point Circle::GetCenter()
{
	return m_center;
}

double Circle::GetRadius() const
{
	return m_radius;
}

std::string Circle::ToString() const
{
	stringstream colors;
	colors << hex << m_outlineColor << ' ' << m_fillColor;
	return "circle: " + m_center.ToString() + ' ' + to_string(m_radius) + ' ' + colors.str();
}

uint32_t Circle::GetOutlineColor() const
{
	return m_outlineColor;
}

double Circle::GetPerimeter() const
{
	return 2 * M_PI * m_radius;
}

uint32_t Circle::GetFillColor() const
{
	return m_fillColor;
}

double Circle::GetArea() const
{
	return M_PI * m_radius * m_radius;
}