#include "electricalTool.h"
#include <iostream>
#pragma warning(disable:4996)
void ElectricalTool::copyFrom(const ElectricalTool& other)
{
    try
    {
        setBrand(other.brand);
        setModel(other.model);
        setSerialNumber(other.serialNumber);
        setKW(other.kW);
        isReleased = other.isReleased;
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << e.what() << std::endl;
        if (brand != nullptr) {
            delete[] brand;
        }
        if (model != nullptr) {
            delete[] model;
        }
        if (serialNumber != nullptr) {
            delete[] serialNumber;
        }
    }
}

void ElectricalTool::free()
{
    delete[] brand;
    delete[] model;
    delete[] serialNumber;
    kW = 0;
}

void ElectricalTool::setBrand(const char* brand)
{
    if (brand == nullptr) {
        throw std::invalid_argument("Brand must be diff from nullptr.");
    }
    if (this->brand != nullptr) {
        delete[] this->brand;
    }
    this->brand = new char[strlen(brand) + 1];
    strcpy(this->brand, brand);
}
void ElectricalTool::setModel(const char* model)
{
    if (model == nullptr) {
        throw std::invalid_argument("Model must be diff from nullptr.");
    }
    if (this->model != nullptr) {
        delete[] this->model;
    }
    this->model = new char[strlen(model) + 1];
    strcpy(this->model, model);
}
void ElectricalTool::setSerialNumber(const char* serialNumber)
{
    if (serialNumber == nullptr) {
        throw std::invalid_argument("Serial number must be diff from nullptr.");
    }
    if (this->serialNumber != nullptr) {
        delete[] this->serialNumber;
    }
    this->serialNumber = new char[strlen(serialNumber) + 1];
    strcpy(this->serialNumber, serialNumber);
}

void ElectricalTool::setKW(const double kW)
{
    if (kW < 0) {
        throw std::invalid_argument("Kw must be bigger than 0.");
    }
    this->kW = kW;
}


ElectricalTool::ElectricalTool(const char* brand, const char* model, const char* serialNumber, const double kW)
{
    try
    {
        setBrand(brand);
        setModel(model);
        setSerialNumber(serialNumber);
        setKW(kW);
        this->isReleased = false;
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << e.what() << std::endl;
        if (this->brand != nullptr) {
            delete[] this->brand;
        }
        if (this->model != nullptr) {
            delete[] this->model;
        }
        if (this->serialNumber != nullptr) {
            delete[] this->serialNumber;
        }
    }
}

ElectricalTool::ElectricalTool(const ElectricalTool& other)
{
    copyFrom(other);
}

ElectricalTool& ElectricalTool::operator=(const ElectricalTool& other)
{
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

ElectricalTool::~ElectricalTool()
{
    free();
}

void ElectricalTool::changeRealeasedOnElec()
{
    if (isReleased == false) {
        isReleased = true;
    }
    else {
        isReleased = false;
    }
}

const char* ElectricalTool::getBrand() const
{
    return brand;
}

const char* ElectricalTool::getModel() const
{
    return model;
}

const char* ElectricalTool::getSerialNumber() const
{
    return serialNumber;
}

double ElectricalTool::getKW() const
{
    return kW;
}

bool ElectricalTool::getReleased() const
{
    return isReleased;
}
