#include "Rectangle.h"
#include <sstream>

using namespace std;

MyRectangle::MyRectangle(Point vertex1, Point vertex2, uint32_t outlineColor, uint32_t fillColor)
	: m_vertex1(vertex1)
	, m_vertex2(vertex2)
	, m_outlineColor(outlineColor)
	, m_fillColor(fillColor)
{
}

MyRectangle::MyRectangle(double x1, double y1, double x2, double y2, uint32_t outlineColor, uint32_t fillColor)
	: MyRectangle(Point(x1, y1), Point(x2, y2), outlineColor, fillColor)
{
}

Point MyRectangle::GetLeftTop()
{
	return m_vertex1;
}

Point MyRectangle::GetRightBottom()
{
	return m_vertex2;
}

double MyRectangle::GetWidth() const
{
	return abs(m_vertex1.x - m_vertex2.x);
}

double MyRectangle::GetHeight() const
{
	return abs(m_vertex1.y - m_vertex2.y);
}

uint32_t MyRectangle::GetOutlineColor() const
{
	return m_outlineColor;
}

uint32_t MyRectangle::GetFillColor() const
{
	return m_fillColor;
}

std::string MyRectangle::ToString() const
{
	stringstream colors;
	colors << hex << m_outlineColor << ' ' << m_fillColor;
	return "rectangle: " + m_vertex1.ToString() + ' ' + m_vertex2.ToString() + ' ' + colors.str();
}

double MyRectangle::GetPerimeter() const
{
	return 2 * (this->GetWidth() + this->GetHeight());
}

double MyRectangle::GetArea() const
{
	return this->GetWidth() * this->GetHeight();
}