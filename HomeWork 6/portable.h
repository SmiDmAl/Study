#pragma once
#include <stdint.h>
#include <iostream>
#include <string>

using namespace std;

class portable_t
{
public:
	portable_t();
	portable_t(uint32_t portWeight, uint32_t portCapacityOfBattery, float portVoltageofBattery, bool portAccumulator );
	~portable_t();

	void setWeight(uint32_t portWeight);
	void setCapacity(uint32_t portCapacityOfBattery);
	void setVoltage(float portVoltageofBattery);
	void setAccum(bool portAccumulator);

	uint32_t getWeight(void);
	uint32_t getCapacity(void);
	float getVoltage(void);
	bool getAccum(void);

	virtual void writeInfo(void);

protected:
	uint32_t weight;			// in gramms
	uint32_t batteryCapacity;   // in mAh
	float batteryVoltage;		// in Volts
	bool accum;					// true if source is accum - false if batteries 
};

