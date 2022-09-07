
#include <stdint.h>
#include <iostream>
#include <string>
#include "device.h"
#include "portable.h"
#include "products.h"

using namespace std;

TV_t::TV_t(string deviceName, string deviceManufactorer, uint64_t deviceSerialNumber, uint64_t deviceModel_ID, float devicePower, float tvScreenSize)
{
	name = deviceName;
	manufactorer = deviceManufactorer;
	SN = deviceSerialNumber;
	model_ID = deviceModel_ID;
	power = devicePower;
	_screenSize = tvScreenSize;
}

TV_t::TV_t()
{
}

TV_t::~TV_t()
{
}

void TV_t::setScreenSize(float tvScreenSize)
{
	_screenSize = tvScreenSize;
}

float TV_t::getScreenSize(void)
{
	return _screenSize;
}

void TV_t::writeInfo(void)
{
	cout << "Name: " << getName() << endl;
	cout << "Manufactorer: " << getManufactorer() << endl;
	cout << "Serial number: " << getSN() << endl;
	cout << "Power: " << getPower() << endl;
	cout << "Screen: " << getScreenSize() << endl;
	cout << endl;
}

notebook_t::notebook_t()
{
}

notebook_t::notebook_t(string deviceName, string deviceManufactorer, uint64_t deviceSerialNumber, uint64_t deviceModel_ID, float devicePower, uint32_t portWeight, uint32_t portCapacityOfBattery, float portVoltageofBattery, bool portAccumulator)
{
	name = deviceName;
	manufactorer = deviceManufactorer;
	SN = deviceSerialNumber;
	model_ID = deviceModel_ID;
	power = devicePower;
	weight = portWeight;
	batteryCapacity = portCapacityOfBattery;
	batteryVoltage = portVoltageofBattery;
	accum = portAccumulator;
}

notebook_t::~notebook_t()
{
}

void notebook_t::writeInfo(void)
{
	cout << "Name: " << getName() << endl;
	cout << "Manufactorer: " << getManufactorer() << endl;
	cout << "Serial number: " << getSN() << endl;
	cout << "Power: " << getPower() << endl;
	cout << "Weigth: " << getWeight() << endl;
	cout << "Capacity: " << getCapacity() << endl;
	cout << "Voltage: " << getVoltage() << endl;
	cout << "Have accumulator: " << getAccum() << endl;
	cout << endl;
}
