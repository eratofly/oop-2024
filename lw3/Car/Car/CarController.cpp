#include "CarController.h"
#include <iostream>
#include <sstream>
#include <string>

CarController::CarController(Car& car, std::istream& input, std::ostream& output)
	: m_car(car)
	, m_input(input)
	, m_output(output)
	, m_actionMap({
		  { "EngineOn", [this](std::istream& strm) {
			   EngineOn(strm);
		   } },
		  { "EngineOff", [this](std::istream& strm) {
			   EngineOff(strm);
		   } },
		  { "Info", [this](std::istream& strm) {
			   Info(strm);
		   } },
		  { "SetGear", [this](std::istream& strm) {
			   SetGear(strm);
		   } },
		  { "SetSpeed", [this](std::istream& strm) {
			   SetSpeed(strm);
		   } },
	  })
{
}

bool CarController::HandleCommand()
{
	std::string commandLine;
	std::getline(m_input, commandLine);
	std::istringstream strm(commandLine);

	std::string action;
	strm >> action;

	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		it->second(strm);
		return true;
	}

	return false;
}

void CarController::EngineOn(std::istream& /*args*/)
{
	m_car.TurnOnEngine();
	m_output << "Engine is turned on" << "\n";
}

void CarController::EngineOff(std::istream& /*args*/)
{
	if (m_car.TurnOffEngine())
	{
		m_output << "Engine is turned off\n";
	}
	else
	{
		m_output << "Car mast be at speed and gear 0\n";
	}
}

void CarController::Info(std::istream& args /*args*/)
{
	if (m_car.IsTurnedOn())
	{
		m_output << "Engine is turned on\n";
		m_output << "Movement direction: ";
		switch (m_car.GetDirection())
		{
		case CDirection::FORWARD:
			m_output << "forward\n";
			break;
		case CDirection::BACKWARD:
			m_output << "backward\n";
			break;
		case CDirection::STANDING:
			m_output << "standing still\n";
			break;
		}
		m_output << "Speed: " << m_car.GetSpeed() << "\n";
		m_output << "Gear: " << m_car.GetGear() << "\n";
	}
	else
	{
		m_output << "Engine is turned off\n";
	}
}

void CarController::SetGear(std::istream& input)
{
	std::string inputString;
	input >> inputString;

	try
	{
		int gear = stoi(inputString);
		if (m_car.SetGear(gear))
		{
			m_output << "Selected gear: " << std::to_string(m_car.GetGear()) << "\n";
		}
		else
		{
			if (m_car.IsTurnedOn())
			{
				m_output << "Selected gear is out of speed range!\n";
			}
			else
			{
				m_output << "Engine is turned off!\n";
			}
		}
	}
	catch (...)
	{
		m_output << "Input must be a decimal number\n";
	}
}

void CarController::SetSpeed(std::istream& input)
{
	std::string inputString;
	input >> inputString;

	try
	{
		int speed = stoi(inputString);
		if (m_car.SetSpeed(speed))
		{
			m_output << "Selected speed: " << std::to_string(m_car.GetSpeed()) << "\n";
		}
		else
		{
			if (m_car.IsTurnedOn())
			{
				m_output << "Selected speed is out of gear speed range!\n";
			}
			else
			{
				m_output << "Engine is turned off!\n";
			}
		}
	}
	catch (...)
	{
		m_output << "Input must be a decimal number\n";
	}
}



