#pragma once

//не пишем С перед enum
enum class CDirection
{
	FORWARD,
	STANDING,
	BACKWARD,
};

class Car
{
public:
	bool IsTurnedOn() const;
	CDirection GetDirection() const;
	int GetSpeed() const; //тут возвращать по модулю
	int GetGear() const;

	bool TurnOnEngine();
	bool TurnOffEngine();
	bool SetGear(int gear);
	bool SetSpeed(int speed);

private:
	bool m_engineOn = false;
	int m_gear = 0;
	int m_speed = 0;// хранить скорость со знаком
};

//на нейтрале можно двигаться назад
