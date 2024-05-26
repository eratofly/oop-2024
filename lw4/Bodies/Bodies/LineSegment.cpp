#include "LineSegment.h"
#include <sstream>
#include <string>

LineSegment::LineSegment(Point startPoint, Point endPoint, uint32_t outlineColor)
	: m_startPoint(startPoint)
	, m_endPoint(endPoint)
	, m_outlineColor(outlineColor)
{
}

LineSegment::LineSegment(double x1, double y1, double x2, double y2, uint32_t outlineColor)
	: LineSegment(Point(x1, y1), Point(x2, y2), outlineColor)
{
}

Point LineSegment::GetStartPoint() const
{
	return m_startPoint;
}

Point LineSegment::GetEndPoint() const
{
	return m_endPoint;
}

double LineSegment::GetArea() const
{
	return 0;
}

double LineSegment::GetPerimeter() const
{
	return GetDistance(m_startPoint, m_endPoint);
}

std::string LineSegment::ToString() const
{
	std::stringstream color;
	color << std::hex << m_outlineColor;
	return "line segment: " + m_startPoint.ToString() + ' ' + m_endPoint.ToString() + ' ' + color.str();
}

uint32_t LineSegment::GetOutlineColor() const
{
	return m_outlineColor;
}
