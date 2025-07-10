#include "DigitalDevice.h"

DigitalDevice::DigitalDevice(std::string a_name, IDevicePresenter* presenter)
	: Device(a_name, presenter) {
	this->minId = 10000;
	this->maxId = 19999;
}
std::string DigitalDevice::getDevicePrefix() const
{
	return "DD";
}
