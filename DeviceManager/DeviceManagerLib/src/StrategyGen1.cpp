#include "StrategyGen1.h"

 

std::string StrategyGen1::Execute( DigitalDeviceVariantC* device )
{
	int currentPercentage = device->getInternalPercentage();

	currentPercentage += 10;

	if ( currentPercentage > 100 )
	{
		currentPercentage = 100;
	}
	device->setInternalPercentage(currentPercentage);
	return std::to_string( currentPercentage ) + "%";

}
std::string StrategyGen1::Peek(DigitalDeviceVariantC* device  ) const
{

	int currentPercentage = device->getInternalPercentage();

	return std::to_string( currentPercentage ) + "%";
}
