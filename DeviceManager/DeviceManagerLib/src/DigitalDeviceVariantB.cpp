#include <DigitalDeviceVariantB.h>

DigitalDeviceVariantB::DigitalDeviceVariantB( std::string a_name, IDevicePresenter* presenter, IIDGenerator* idGenerator )
	: DigitalDevice( a_name, presenter, idGenerator )
{
}

std::string DigitalDeviceVariantB::getStatus() 
{
	_internalStatus = !_internalStatus; // Toggle status for demonstration
	return _internalStatus ? "On" : "Off";
}
