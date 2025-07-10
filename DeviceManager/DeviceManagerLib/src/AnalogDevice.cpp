#include "AnalogDevice.h"
#include <iomanip>
#include <sstream> 

AnalogDevice::AnalogDevice(std::string a_name, IDevicePresenter* presenter)
	: Device(a_name, presenter) {
	this->minId = 100;
	this->maxId = 9999;
	// Initialize the AnalogDevice specific properties if any
}

std::string AnalogDevice::getDevicePrefix() const
{
	return "AD";
}




