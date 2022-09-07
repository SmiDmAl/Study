#pragma once

#include <stdint.h>
#include <iostream>
#include <string>
#include "device.h"
#include "portable.h"

using namespace std;

class TV_t : public device_t
{
public:
	TV_t(string deviceName, string deviceManufactorer, uint64_t deviceSerialNumber, uint64_t deviceModel_ID, float devicePower, float tvScreenSize);
	TV_t();
	~TV_t();
	void setScreenSize(float tvScreenSize);
	float getScreenSize(void);

	void writeInfo(void) override;

protected:
	float _screenSize;

};

class notebook_t : virtual public device_t, portable_t
{
public: 
	notebook_t();
	notebook_t(string deviceName, string deviceManufactorer, uint64_t deviceSerialNumber, uint64_t deviceModel_ID, float devicePower, uint32_t portWeight, uint32_t portCapacityOfBattery, float portVoltageofBattery, bool portAccumulator);
	~notebook_t();

	void writeInfo(void) override;

};