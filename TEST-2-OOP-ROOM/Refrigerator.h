#pragma once
#include "electricalTool.h"
class Refrigerator : public ElectricalTool {
private:
	unsigned count;
public:
	Refrigerator(const unsigned count, const char* brand, const char* model, const char* serialNumber, const double kW);
	Refrigerator(const Refrigerator& other);
	Refrigerator& operator=(const Refrigerator& other);

	double getKWOnDevice() const;
	void changeRealeased();
	void print() const;
	ElectricalTool* clone() const override;
};