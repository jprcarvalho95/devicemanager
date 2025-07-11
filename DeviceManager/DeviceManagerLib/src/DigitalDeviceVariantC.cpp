#include <Constants.h>
#include <DigitalDeviceVariantC.h>
#include <IStatusStrategy.h>
#include <stdexcept>

DigitalDeviceVariantC::DigitalDeviceVariantC(
	std::string a_name, IDevicePresenter* presenter, IIDGenerator* idGenerator, std::unordered_map<Constants::DigitalDevice::Generation, IStatusStrategy*> strategies )
	: DigitalDevice( a_name, presenter, idGenerator )
{
	_availableStrategies = strategies;

	if ( this->getDeviceID() >= 15000 )
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
		return DigitalDevice::getDescription() + " (Gen 2)";
	}
	else
	{
		throw std::runtime_error( "Unknown generation" );
	}
}
int DigitalDeviceVariantC::getInternalPercentage()
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
std::string DigitalDeviceVariantC::getStatus()  {
	IStatusStrategy* strategy = _availableStrategies.at( this->_generation );
	std::string status = strategy->Peek( this );
	return status;
}

