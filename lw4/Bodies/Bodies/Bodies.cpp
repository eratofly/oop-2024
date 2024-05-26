#include "ShapesController.h"

int main()
{
	ShapesController controller;
	for (std::string line; std::getline(std::cin, line);)
	{	
		controller.ParseShape(line);
	}
	if (auto* smallestShape = controller.FindShapeWithSmallestPerimeter())
	{
		std::cout << "min perimeter: " << controller.FindShapeWithSmallestPerimeter()->ToString() << std::endl;
 
	}
	if (auto* smallestShape = controller.FindShapeWithGreatestArea())
	{
		std::cout << "the greatest area: " << controller.FindShapeWithGreatestArea() << std::endl;
	}

	return 0;
}