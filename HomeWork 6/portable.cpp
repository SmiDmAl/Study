
#include <stdint.h>
#include <iostream>
#include <string>
#include "portable.h"

using namespace std;

portable_t::portable_t()
{
}

portable_t::portable_t(uint32_t portWeight, uint32_t portCapacityOfBattery, float portVoltageofBattery, bool portAccumulator)
{
	weight = portWeight;
	batteryCapacity = portCapacityOfBattery;
	batteryVoltage = portVoltageofBattery;
	accum = portAccumulator;
}

portable_t::~portable_t()
{

}

void portable_t::setWeight(uint32_t portWeight)
{
	weight = portWeight;
}

void portable_t::setCapacity(uint32_t portCapacityOfBattery)
{
	batteryCapacity = portCapacityOfBattery;
}

void portable_t::setVoltage(float portVoltageofBattery)
{
	batteryVoltage = portVoltageofBattery;
}

void portable_t::setAccum(bool portAccumulator)
{
	accum = portAccumulator;
}

uint32_t portable_t::getWeight(void)
{
	return uint32_t(weight);
}

uint32_t portable_t::getCapacity(void)
{
	return uint32_t(batteryCapacity);
}

float portable_t::getVoltage(void)
{
	return batteryVoltage;
}

bool portable_t::getAccum(void)
{
	return accum;
}

void portable_t::writeInfo(void)
{
	cout << "Weigth: " << getWeight() << endl;
	cout << "Capacity: " << getCapacity() << endl;
	cout << "Voltage: " << getVoltage() << endl;
	cout << "Have accumulator: " << getAccum() << endl;
	cout << endl;
}
