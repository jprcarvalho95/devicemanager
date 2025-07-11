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


