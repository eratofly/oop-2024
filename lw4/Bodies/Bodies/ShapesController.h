#pragma once
#include "IShape.h"
#include "Circle.h"
#include "LineSegment.h"
#include "Rectangle.h"
#include "Triangle.h"
#include <vector>

class ShapesController
{
public:
	//используя parseshape, добавляю фигуры,
	bool ParseShape(std::string const& str);
	IShape* FindShapeWithGreatestArea();
	IShape* FindShapeWithSmallestPerimeter();
	const std::vector<std::unique_ptr<IShape>>& GetShapes() const;

private: 
	static std::unique_ptr<Circle> CreateCircle(std::istream& parametersInput);
	static std::unique_ptr<LineSegment> CreateLine(std::istream& parametersInput);
	static std::unique_ptr<MyRectangle> CreateRectangle(std::istream& parametersInput);
	static std::unique_ptr<Triangle> CreateTriangle(std::istream& parametersInput);
	std::vector<std::unique_ptr<IShape>> m_shapes;
};
