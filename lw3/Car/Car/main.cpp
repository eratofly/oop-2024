#include "Car.h"
#include "CarController.h"
#include <iostream>

int main()
{
	Car car;
	CarController consoleControl(car, std::cin, std::cout);

	while (!std::cin.eof() && !std::cin.fail())
	{
		std::cout << "> ";
		if (!consoleControl.HandleCommand())
		{
			std::cout << "Unknown command!" << std::endl;
		}
	}

	return 0;
}

//не получается включить заднюю передачу
//автомобиль выключился не смотря на то, что скорость была