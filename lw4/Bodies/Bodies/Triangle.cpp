#include "Triangle.h"
#include <sstream>

using namespace std;

Triangle::Triangle(Point vertex1, Point vertex2, Point vertex3, uint32_t outlineColor, uint32_t fillColor)
	: m_vertex1(vertex1)
	, m_vertex2(vertex2)
	, m_vertex3(vertex3)
	, m_outlineColor(outlineColor)
	, m_fillColor(fillColor)
{
}

Triangle::Triangle(double x1, double y1, double x2, double y2, double x3, double y3, uint32_t outlineColor, uint32_t fillColor)
	: Triangle(Point(x1, y1), Point(x2, y2), Point(x3, y3), outlineColor, fillColor)
{
}

double Triangle::GetPerimeter() const
{
	return GetDistance(m_vertex1, m_vertex2) + GetDistance(m_vertex3, m_vertex2) + GetDistance(m_vertex1, m_vertex3);
}

double Triangle::GetArea() const
{
	double a = GetDistance(m_vertex1, m_vertex2);
	double b = GetDistance(m_vertex3, m_vertex2);
	double c = GetDistance(m_vertex1, m_vertex3);
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

std::string Triangle::ToString() const
{
	stringstream colors;
	colors << hex << m_outlineColor << ' ' << m_fillColor;
	return "triangle: " + m_vertex1.ToString() + ' ' + m_vertex2.ToString() + ' ' + m_vertex3.ToString() + ' ' + colors.str();
}

uint32_t Triangle::GetOutlineColor() const
{
	return m_outlineColor;
}

uint32_t Triangle::GetFillColor() const
{
	return m_fillColor;
}

Point Triangle::GetVertex1()
{
	return m_vertex1;
}

Point Triangle::GetVertex2()
{
	return m_vertex2;
}

Point Triangle::GetVertex3()
{
	return m_vertex3;
}