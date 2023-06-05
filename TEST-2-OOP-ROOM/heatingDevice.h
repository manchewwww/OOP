#pragma once
#include "electricalTool.h"

class HeatingDevice : public ElectricalTool {
public:
	HeatingDevice(const char* brand, const char* model, const char* serialNumber, const double kW);
	HeatingDevice(const HeatingDevice& other);
	HeatingDevice& operator=(const HeatingDevice& other);

	double getKWOnDevice() const;
	void changeRealeased() override;
	void print() const override;
	ElectricalTool* clone() const override;

};