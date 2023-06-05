#include "Refrigerator.h"
#include <iostream>
#pragma warning(disable:4996)

Refrigerator::Refrigerator(const unsigned count, const char* brand, const char* model, const char* serialNumber, const double kW) : ElectricalTool(brand,model,serialNumber, count * kW)
{
    this->count = count;
}

Refrigerator::Refrigerator(const Refrigerator& other) : ElectricalTool(other)
{
    count = other.count;
}

Refrigerator& Refrigerator::operator=(const Refrigerator& other)
{
    ElectricalTool::operator=(other);
    count = other.count;
    return *this;
}

double Refrigerator::getKWOnDevice() const
{
    return getKW();
}

void Refrigerator::changeRealeased()
{
    changeRealeasedOnElec();
}

void Refrigerator::print() const
{
    std::cout << getModel() << std::endl;
    std::cout << getBrand() << std::endl;
    std::cout << getKWOnDevice() << std::endl;
}

ElectricalTool* Refrigerator::clone() const
{
    return new Refrigerator(*this);
}
