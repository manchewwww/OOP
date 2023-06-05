#pragma once

class ElectricalTool {
private:
	char* brand;
	char* model;
	char* serialNumber;
	double kW;
	bool isReleased;

	void copyFrom(const ElectricalTool& other);
	void free();
	void setBrand(const char* brand);
	void setModel(const char* model);
	void setSerialNumber(const char* serialNumber);
	void setKW(const double kW);
public:
	ElectricalTool(const char* brand, const char* model, const char* serialNumber, const double kW);
	ElectricalTool(const ElectricalTool& other);
	ElectricalTool& operator=(const ElectricalTool& other);
	virtual ~ElectricalTool();
	void changeRealeasedOnElec();

	const char* getBrand() const;
	const char* getModel() const;
	const char* getSerialNumber() const;
	double getKW() const;
	bool getReleased() const;

	virtual double getKWOnDevice() const = 0;
	virtual void changeRealeased() = 0;
	virtual void print() const = 0;
	virtual ElectricalTool* clone() const = 0;
};