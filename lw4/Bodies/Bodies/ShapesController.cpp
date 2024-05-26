#include "ShapesController.h"
#include "IShape.h"
#include <memory>
#include <sstream>
#include <vector>

void GetParameters(std::istream& parametersInput, std::vector<double>& sizeParameters, std::vector<uint32_t>& colorParameters, int count)
{
	std::string parameter;
	double sizeParameter;
	uint32_t colorParameter;
	while (parametersInput >> parameter)
	{
		if (std::istringstream(parameter) >> sizeParameter && count)
		{
			sizeParameters.push_back(sizeParameter);
			--count;
		}
		else if (std::istringstream(parameter) >> std::hex >> colorParameter)
		{
			colorParameters.push_back(colorParameter);
		}
	}
}

std::unique_ptr<LineSegment> ShapesController::CreateLine(std::istream& parametersInput)
{
	std::vector<double> sizeParameters;
	std::vector<uint32_t> colorParameters;
	const int REQUIRED_PARAMETERS = 4;

	GetParameters(parametersInput, sizeParameters, colorParameters, REQUIRED_PARAMETERS);

	if (sizeParameters.size() != REQUIRED_PARAMETERS || colorParameters.size() > 2)
		return nullptr;

	switch (colorParameters.size())
	{
	case 0:
		return std::make_unique<LineSegment>(sizeParameters[0], sizeParameters[1], sizeParameters[2], sizeParameters[3]);
	case 1:
		return std::make_unique<LineSegment>(sizeParameters[0], sizeParameters[1], sizeParameters[2], sizeParameters[3], colorParameters[0]);
	}
	
	return nullptr;
}

std::unique_ptr<Circle> ShapesController::CreateCircle(std::istream& parametersInput)
{
	std::vector<double> sizeParameters;
	std::vector<uint32_t> colorParameters;
	const int REQUIRED_PARAMETERS = 3;

	GetParameters(parametersInput, sizeParameters, colorParameters, REQUIRED_PARAMETERS);

	if (sizeParameters.size() != REQUIRED_PARAMETERS || colorParameters.size() > 2)
		return nullptr;

	switch (colorParameters.size())
	{
	case 0:
		return std::make_unique<Circle>(sizeParameters[0], sizeParameters[1], sizeParameters[2], sizeParameters[3]);
	case 1:
		return std::make_unique<Circle>(sizeParameters[0], sizeParameters[1], sizeParameters[2], colorParameters[0]);
	case 2:
		return std::make_unique<Circle>(sizeParameters[0], sizeParameters[1], sizeParameters[2], colorParameters[0], colorParameters[1]);
	}
	
	return nullptr;
}

std::unique_ptr<MyRectangle> ShapesController::CreateRectangle(std::istream& parametersInput)
{
	std::vector<double> sizeParameters;
	std::vector<uint32_t> colorParameters;
	const int REQUIRED_PARAMETERS = 4;

	GetParameters(parametersInput, sizeParameters, colorParameters, REQUIRED_PARAMETERS);

	if (sizeParameters.size() != REQUIRED_PARAMETERS || colorParameters.size() > 2)
		return nullptr;

	switch (colorParameters.size())
	{
	case 0:
		return std::make_unique<MyRectangle>(sizeParameters[0], sizeParameters[1], sizeParameters[2], sizeParameters[3]);
	case 1:
		return std::make_unique<MyRectangle>(sizeParameters[0], sizeParameters[1], sizeParameters[2], sizeParameters[3], colorParameters[0]);
	case 2:
		return std::make_unique<MyRectangle>(sizeParameters[0], sizeParameters[1], sizeParameters[2], sizeParameters[3], colorParameters[0], colorParameters[1]);
	}

	return nullptr;
}

std::unique_ptr<Triangle> ShapesController::CreateTriangle(std::istream& parametersInput)
{
	std::vector<double> sizeParameters;
	std::vector<uint32_t> colorParameters;
	const int REQUIRED_PARAMETERS = 6;

	GetParameters(parametersInput, sizeParameters, colorParameters, REQUIRED_PARAMETERS);

	if (sizeParameters.size() != REQUIRED_PARAMETERS || colorParameters.size() > 2)
		return nullptr;

	switch (colorParameters.size())
	{
	case 0:
		return std::make_unique<Triangle>(sizeParameters[0], sizeParameters[1], sizeParameters[2], sizeParameters[3], sizeParameters[4], sizeParameters[5]);
	case 1:
		return std::make_unique<Triangle>(sizeParameters[0], sizeParameters[1], sizeParameters[2], sizeParameters[3], sizeParameters[4], sizeParameters[5], colorParameters[0]);
	case 2:
		return std::make_unique<Triangle>(sizeParameters[0], sizeParameters[1], sizeParameters[2], sizeParameters[3], sizeParameters[4], sizeParameters[5], colorParameters[0], colorParameters[1]);
	}

	return nullptr;
}

bool ShapesController::ParseShape(std::string const& str)
{
	auto parametersInput = std::istringstream(str);
	std::string shapeType;
	parametersInput >> shapeType;

	if (shapeType == "line")
	{
		m_shapes.push_back(this->CreateLine(parametersInput));
	}
	if (shapeType == "circle")
	{
		m_shapes.push_back(this->CreateCircle(parametersInput));
	}
	if (shapeType == "triangle")
	{
		m_shapes.push_back(this->CreateTriangle(parametersInput));
	}
	if (shapeType == "rectangle")
	{
		m_shapes.push_back(this->CreateRectangle(parametersInput));
	}

	return 1;
}

IShape* ShapesController::FindShapeWithGreatestArea()
{
	if (m_shapes.empty())
		return nullptr;
	return max_element(
		m_shapes.begin(),
		m_shapes.end(),
		[](const std::unique_ptr<IShape>& s1, const std::unique_ptr<IShape>& s2) {
			return s1->GetArea() < s2->GetArea();
		})
		->get();
}

IShape* ShapesController::FindShapeWithSmallestPerimeter()
{
	if (m_shapes.empty())
		return nullptr;
	return min_element(
		m_shapes.begin(),
		m_shapes.end(),
		[](const std::unique_ptr<IShape>& s1, const std::unique_ptr<IShape>& s2) {
			return s1->GetPerimeter() < s2->GetPerimeter();
		})
		->get();
}

const std::vector<std::unique_ptr<IShape>>& ShapesController::GetShapes() const
{
	return m_shapes;
}
