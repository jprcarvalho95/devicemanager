#include "DigitalDeviceVariantA.h"
#include <iomanip>
#include <sstream>
DigitalDeviceVariantA::DigitalDeviceVariantA( std::string a_name
	, IDevicePresenter* presenter
	, IIDGenerator* idGenerator
	, IRandomizer* randomizer)

	: DigitalDevice( a_name, presenter, idGenerator )
{
	_randomizer = randomizer;
}

std::string DigitalDeviceVariantA::getStatus()
{
	float randomValue = _randomizer->getRandomFloat( -50.0f, 70.0f );
	this->_internalStatus = randomValue;


	if ( randomValue == -50.0f )
	{
		return "Low";
	}

	if ( randomValue == 70.0f )
	{
		return "High";
	}

	// Truncate to two decimal places
	std::ostringstream oss;
	oss << std::fixed << std::setprecision( 1 ) << randomValue;

	return oss.str();

	
}


