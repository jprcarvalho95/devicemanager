#include "Constants.h"
#include "DigitalDeviceVariantC.h"
#include "IStatusStrategy.h"
#include <stdexcept>
#include "IIDGenerator.h"
#include "IDevicePresenter.h"

DigitalDeviceVariantC::DigitalDeviceVariantC(
	  std::string a_name
	, IDevicePresenter* presenter
	, IIDGenerator* idGenerator
	, std::unordered_map<Constants::DigitalDevice::Generation, IStatusStrategy*> strategies )
	: DigitalDevice( a_name, presenter, idGenerator )
{
	_availableStrategies = strategies;

	if ( this->getDeviceID() >= Constants::DigitalDevice::ID_GEN1_CAP )
	{
		_generation = Constants::DigitalDevice::Generation::Gen2;
	}
	else
	{
		_generation = Constants::DigitalDevice::Generation::Gen1;
	}
}

std::string DigitalDeviceVariantC::getDescription() const
{
	if ( this->_generation == Constants::DigitalDevice::Generation::Gen1 )
	{
		return DigitalDevice::getDescription();
	}
	else if ( this->_generation == Constants::DigitalDevice::Generation::Gen2 )
	{
		return DigitalDevice::getDescription() + std::string { Constants::DigitalDevice::GEN2_OUTPUT_MODIFIER };
	}
	else
	{
		throw std::runtime_error( "Unknown generation" );
	}
}
int DigitalDeviceVariantC::getInternalPercentage() const
{
	return this->_internalPercentage;
}
void DigitalDeviceVariantC::setInternalPercentage(int newPercentage)
{
	this->_internalPercentage = newPercentage;
}
std::string DigitalDeviceVariantC::updateStatus()
{
	IStatusStrategy* strategy = _availableStrategies.at( this->_generation );
	std::string status = strategy->Execute( this );
	return status;
}
std::string DigitalDeviceVariantC::getStatus() const{
	IStatusStrategy* strategy = _availableStrategies.at( this->_generation );
	const DigitalDeviceVariantC* constThis = this; // Use const pointer to call const method
	std::string status = strategy->Peek( constThis );
	return status;
}

