#include "heatingDevice.h"
#include <iostream>
#pragma warning(disable:4996)

HeatingDevice::HeatingDevice(const char* brand, const char* model, const char* serialNumber, const double kW) : ElectricalTool(brand, model, serialNumber, kW)
{
}

HeatingDevice::HeatingDevice(const HeatingDevice& other) : ElectricalTool(other)
{
}

HeatingDevice& HeatingDevice::operator=(const HeatingDevice& other)
{
	ElectricalTool::operator=(other);
	return *this;
}

double HeatingDevice::getKWOnDevice() const
{
	if (getReleased()) {
		return getKW();
	}
	return 0;
}

void HeatingDevice::changeRealeased()
{
	changeRealeasedOnElec();
}

void HeatingDevice::print() const
{
	std::cout << getModel() << std::endl;
	std::cout << getBrand() << std::endl;
	std::cout << getKWOnDevice() << std::endl;
}

ElectricalTool* HeatingDevice::clone() const
{
	return new HeatingDevice(*this);
}
