
#include <stdint.h>
#include <iostream>
#include <string>
#include "device.h"
using namespace std;


device_t::device_t()
{

}

device_t::device_t(string deviceName, uint64_t deviceSerialNumber, uint64_t deviceModel_ID)
{
	name = deviceName;
	SN = deviceSerialNumber;
	model_ID = deviceModel_ID;
}

device_t::device_t(string deviceName, string deviceManufactorer, uint64_t deviceSerialNumber, uint64_t deviceModel_ID, float devicePower)
{
	name = deviceName;
	manufactorer = deviceManufactorer;
	SN = deviceSerialNumber;
	model_ID = deviceModel_ID;
	power = devicePower;
}

device_t::~device_t()
{

}

void device_t::setName(string deviceName)
{
	name = deviceName;
}

void device_t::setManufactorer(string deviceManufactorer)
{
	manufactorer = deviceManufactorer;
}

void device_t::setModel_ID(uint64_t deviceModel_ID)
{
	model_ID = deviceModel_ID;
}

void device_t::setSN(uint64_t deviceSerialNumber)
{
	SN = deviceSerialNumber;
}

void device_t::setPower(float devicePower)
{
	power = devicePower;
}

string device_t::getName(void)
{
	return string(name);
}

string device_t::getManufactorer(void)
{
	return string(manufactorer);
}

uint64_t device_t::getModel_ID(void)
{
	return uint64_t(model_ID);
}

uint64_t device_t::getSN(void)
{
	return uint64_t(SN);
}

float device_t::getPower(void)
{
	return power;
}

void device_t::writeInfo(void)
{
	cout << "Name: " << getName() << endl;
	cout << "Manufactorer: " << getManufactorer() << endl;
	cout << "Serial number: " << getSN() << endl;
	cout << "Power: " << getPower() << endl;
	cout << endl;
}
