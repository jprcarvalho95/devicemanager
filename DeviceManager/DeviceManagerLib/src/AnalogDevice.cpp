#include "AnalogDevice.h"
#include <iomanip>
#include <sstream> 
#include <Constants.h>

AnalogDevice::AnalogDevice(std::string a_name, IDevicePresenter* presenter, IIDGenerator* idGenerator)
	: Device( a_name, presenter, idGenerator )
{
	
}


	std::string AnalogDevice::getDevicePrefix() const
{
	return std::string(Constants::AnalogDevice::PREFIX);
	}




