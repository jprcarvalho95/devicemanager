#pragma once
#include <string>
class IDevice
{

public:
	virtual ~IDevice() = default;
	// Set functions as purely virtual to provide interface behavior
	virtual void printInfo() const = 0;

	virtual std::string getName() const = 0;
	virtual unsigned int getDeviceID() const = 0;
	virtual std::string getDescription() const = 0;
	virtual std::string getDevicePrefix() const = 0;

};

