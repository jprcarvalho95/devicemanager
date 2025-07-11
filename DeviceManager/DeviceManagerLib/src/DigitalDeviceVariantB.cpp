#include <DigitalDeviceVariantB.h>

DigitalDeviceVariantB::DigitalDeviceVariantB( std::string a_name, IDevicePresenter* presenter, IIDGenerator* idGenerator )
	: DigitalDevice( a_name, presenter, idGenerator )
{
}


std::string DigitalDeviceVariantB::updateStatus()
{
	_internalStatus = !_internalStatus; // Toggle status for demonstration
	return getStatus();
}


std::string DigitalDeviceVariantB::getStatus() const
{
	return _internalStatus ? "On" : "Off";
}
