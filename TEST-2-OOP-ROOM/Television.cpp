#include "Television.h"
#include <iostream>
#pragma warning(disable:4996)
void Television::setBrightness(const double brightness)
{
	if (brightness < 0 || brightness > 100) {
		throw std::invalid_argument("Percent must be between 0 and 100.");
	}
	this->brightness = brightness;
}

Television::Television(const double brightness, const char* brand, const char* model, const char* serialNumber, const double kW) : ElectricalTool(brand, model, serialNumber, (brightness / 100) * kW)
{
	try
	{
		setBrightness(brightness);
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << e.what() << std::endl;
	}
}

Television::Television(const Television& other) : ElectricalTool(other)
{
	brightness = other.brightness;
}

Television& Television::operator=(const Television& other)
{
	ElectricalTool::operator=(other);
	brightness = other.brightness;
	return *this;
}

double Television::getKWOnDevice() const
{
	if (getReleased()) {
		return getKW();
	}
	return 0.05;
}
void Television::changeRealeased()
{
	changeRealeasedOnElec();
}

void Television::print() const
{
	std::cout << getModel() << std::endl;
	std::cout << getBrand() << std::endl;
	std::cout << getKWOnDevice() << std::endl;
}

ElectricalTool* Television::clone() const
{
	return new Television(*this);
}
