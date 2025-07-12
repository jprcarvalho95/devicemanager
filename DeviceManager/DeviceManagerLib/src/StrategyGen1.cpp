#include "StrategyGen1.h"
#include "DigitalDeviceVariantC.h"
#include <string>

 

std::string StrategyGen1::Execute( DigitalDeviceVariantC* device )
{
	int currentPercentage = device->getInternalPercentage();

	currentPercentage += 10;

	if ( currentPercentage > 100 )
	{
		currentPercentage = 100;
	}
	device->setInternalPercentage(currentPercentage);

	return Peek( device );

}
std::string StrategyGen1::Peek(const DigitalDeviceVariantC* device  ) const
{

	int currentPercentage = device->getInternalPercentage();

	return std::to_string( currentPercentage ) + "%";
}
