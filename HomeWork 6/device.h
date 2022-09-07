#pragma once

#include <stdint.h>
#include <iostream>
#include <string>
using namespace std;

class device_t
{
public:
	device_t();
	device_t(string deviceName, uint64_t deviceSerialNumber, uint64_t deviceModel_ID);
	device_t(string deviceName, string deviceManufactorer, uint64_t deviceSerialNumber, uint64_t deviceModel_ID, float devicePower);
	~device_t();

	void setName(string deviceName);
	void setManufactorer(string deviceManufactorer);
	void setModel_ID(uint64_t deviceModel_ID);
	void setSN(uint64_t deviceSerialNumber);
	void setPower(float devicePower);

	string getName(void);
	string getManufactorer(void);
	uint64_t getModel_ID(void);
	uint64_t getSN(void);
	float getPower(void);

	virtual void writeInfo(void);

protected:
	string name;
	string manufactorer;
	uint64_t model_ID;	// code number of device in manufactorer lineup
	uint64_t SN;	// serial number of device
	float power;	// power consumption in Watt
};
