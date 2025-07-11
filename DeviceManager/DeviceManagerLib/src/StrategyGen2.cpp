#include <DigitalDeviceVariantC.h>
#include <StrategyGen2.h>

std::string StrategyGen2::Execute( DigitalDeviceVariantC* device )
{
	int currentPercentage = device->getInternalPercentage();

	currentPercentage += 1;

	if ( currentPercentage > 100 )
	{
		currentPercentage = 100;
	}
	device->setInternalPercentage( currentPercentage );

}

std::string StrategyGen2::Peek(const DigitalDeviceVariantC* device ) const {

	int currentPercentage = device->getInternalPercentage();

	if ( currentPercentage == 0 )
	{
		return "Opened";
	}
	else if ( currentPercentage == 100 )
	{
		return "Closed";
	}

	return std::to_string( currentPercentage ) + "%";

}
