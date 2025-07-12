#include "DigitalDeviceVariantA.h"
#include <iomanip>
#include <sstream>
#include "IDevicePresenter.h"
#include "IRandomizer.h"

DigitalDeviceVariantA::DigitalDeviceVariantA( std::string a_name
	, IDevicePresenter* presenter
	, IIDGenerator* idGenerator
	, IRandomizer* randomizer)

	: DigitalDevice( a_name, presenter, idGenerator )
{
	_randomizer = randomizer;
	// Generate an initial random status value
	updateStatus();
}

std::string DigitalDeviceVariantA::updateStatus()
{
	// Generate a random float between -50.0 and 70.0
	float randomValue = _randomizer->getRandomFloat( -50.0f, 70.0f );
	this->_internalStatus = randomValue;
	return std::to_string( this->_internalStatus );
}

std::string DigitalDeviceVariantA::getStatus() const
{
	if ( this->_internalStatus == -50.0f )
	{
		return "Low";
	}

	if ( this->_internalStatus == 70.0f )
	{
		return "High";
	}

	// Truncate to two decimal places
	std::ostringstream oss;
	oss << std::fixed << std::setprecision( 1 ) << this->_internalStatus;

	return oss.str();

	
}


