#include "Device.h"

void Device::free() {
	delete[] brand;
	delete[] model;
	brand = nullptr;
	model = nullptr;
}
void Device::copy(const Device& other) {
	device = other.device;
	brand = new char[strlen(other.brand) + 1];
	model = new char[strlen(other.model) + 1];
	strcpy(brand, other.brand);
	strcpy(model, other.brand);
	price = other.price;
}

Device::Device(const Device& other) {
	copy(other);
}
Device& Device::operator=(const Device& other) {
	if(this != &other){
		free();
		copy(other);
	}
	return *this;
}
Device::~Device() {
	free();
}

void Device::setPrice(const double& price) {
	if (price < 0) {
		throw std::invalid_argument("Invalid price");
	}
	this->price = price;
}
void Device::setDevice(const char* device) {
	if (device == nullptr) {
		throw std::invalid_argument("Invalid device");
	}
	else if (strcmp(device, "compter") == 0) {
		this->device = Type::computer;
	}
	else if (strcmp(device, "laptop") == 0) {
		this->device = Type::laptop;
	}
	else if (strcmp(device, "headphones") == 0) {
		this->device = Type::headphones;
	}
	else if (strcmp(device, "telephone") == 0) {
		this->device = Type::telephone;
	}
	else {
		throw std::invalid_argument("Invalid device");
	}
}
void Device::setBrand(const char* brand) {
	delete[] this->brand;
	this->brand = new char[strlen(brand) + 1];
	strcpy(this->brand, brand);
}
void Device::setModel(const char* model) {
	delete[] this->model;
	this->model = new char[strlen(model) + 1];
	strcpy(this->model, model);
}
