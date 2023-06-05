#pragma once
#include "electricalTool.h"
class Television : public ElectricalTool {
private:
	double brightness;

	void setBrightness(const double brightness);
public:
	Television(const double brightness, const char* brand, const char* model, const char* serialNumber, const double kW);
	Television(const Television& other);
	Television& operator= (const Television& other);

	double getKWOnDevice() const override;
	void changeRealeased();
	void print() const override;
	ElectricalTool* clone() const override;
};