#include "DigitalDeviceVariantB.h"
#include "Constants.h"
DigitalDeviceVariantB::DigitalDeviceVariantB( std::string a_name, IDevicePresenter* presenter, IIDGenerator* idGenerator )
	: DigitalDevice( a_name, presenter, idGenerator )
{
	_internalStatus = false;
}


std::string DigitalDeviceVariantB::updateStatus()
{
	_internalStatus = !_internalStatus;

	return getStatus();
}


std::string DigitalDeviceVariantB::getStatus() const
{
	std::string_view statusView = _internalStatus ? Constants::DigitalDevice::ON : Constants::DigitalDevice::OFF;

	return std::string( statusView );
}
