#include "StrategyGen2.h"
#include "DigitalDeviceVariantC.h"
#include <string>

std::string StrategyGen2::Execute( DigitalDeviceVariantC* device )
{
	int currentPercentage = device->getInternalPercentage();

	currentPercentage += 1;

	if ( currentPercentage > 100 )
	{
		currentPercentage = 100;
	}
	device->setInternalPercentage( currentPercentage );

	return Peek( device ); 
}

std::string StrategyGen2::Peek( const DigitalDeviceVariantC* device ) const
{

	int currentPercentage = device->getInternalPercentage();

	if ( currentPercentage == 0 )
	{
		return std::string( Constants::DigitalDevice::OPENED );
	}
	else if ( currentPercentage == 100 )
	{
		return std::string( Constants::DigitalDevice::CLOSED );
	}

	return std::to_string( currentPercentage ) + "%";
}
