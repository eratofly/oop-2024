#include <iostream>
#include "Car.h"

bool Car::IsTurnedOn() const
{
	return m_engineOn;
}

CDirection Car::GetDirection() const
{
	if (m_speed > 0)
	{
		return CDirection::FORWARD;
	}
	if (m_speed < 0)
	{
		return CDirection::BACKWARD;
	}
	return CDirection::STANDING;
}

int Car::GetSpeed() const
{
	return m_speed;
}

int Car::GetGear() const
{
	return m_gear;
}

bool Car::TurnOnEngine()
{
	m_engineOn = true;
	return m_engineOn;
}

bool Car::TurnOffEngine()
{
	m_engineOn = false;
	return m_engineOn;
}

bool isValidGearAndSpeed(int gear, int speed)
{
	switch (gear)
	{
	case -1:
		return speed <= 0 && speed >= 20;
	case 0:
		return true;
	case 1:
		return speed >= 0 && speed <= 30;
	case 2:
		return speed >= 20 && speed <= 50;
	case 3:
		return speed >= 30 && speed <= 60;
	case 4:
		return speed >= 40 && speed <= 90;
	case 5:
		return speed >= 50 && speed <= 150;
	default:
		return false;
	}
}

bool Car::SetGear(int gear)
{
	if (m_engineOn)
	{
		if (gear != m_gear && !isValidGearAndSpeed(gear, m_speed) || gear == -1 && m_speed != 0)
			return false;
		m_gear = gear;
		return true;
	}

	return gear == 0;
}

bool Car::SetSpeed(int speed)
{
	if (m_engineOn && speed >= 0)
	{
		if (m_gear == 0 && speed > abs(m_speed))
			return false;
		if (m_gear < 0)
			speed *= -1;
		if (!isValidGearAndSpeed(m_gear, speed))
			return false;
		m_speed = speed;
		return true;
	}

	return false;
}
