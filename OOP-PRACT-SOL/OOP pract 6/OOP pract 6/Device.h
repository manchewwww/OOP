#pragma once
#include <iostream>
enum class Type {
	computer,
	laptop,
	telephone,
	headphones
};
class Device {
private:
	Type device;
	char* brand;
	char* model;
	double price;

	void free();
	void copy(const Device& other);
	void setDevice(const char* device);
	void setBrand(const char* brand);
	void setModel(const char* model);
public:

	Device(const char* device, const char* brand, const char* model, double price) {
		setDevice(device);
		setBrand(brand);
		setModel(model);
		setPrice(price);
	}
	Device(const Device& other);
	Device& operator=(const Device& other);
	void setPrice(const double& price);
	~Device();
};