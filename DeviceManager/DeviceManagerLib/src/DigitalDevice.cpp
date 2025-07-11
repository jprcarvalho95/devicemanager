#include "DigitalDevice.h"
#include <Constants.h>

DigitalDevice::DigitalDevice( std::string a_name, IDevicePresenter* presenter, IIDGenerator* idGenerator )
	: Device( a_name, presenter, idGenerator )
{
}
std::string DigitalDevice::getDevicePrefix() const
{
	return std::string( Constants::DigitalDevice::PREFIX );
	;
}

std::string DigitalDevice::getStatus() const
{
	return "Digital Device Status"; // Placeholder implementation
}
std::string DigitalDevice::updateStatus()
{
	return "Digital Device Updated Status"; // Placeholder implementation
}
