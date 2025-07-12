#include "DigitalDeviceFactory.h"
#include "DigitalDevice.h"

std::unique_ptr<IDevice> DigitalDeviceFactory::createDevice( const std::string& name, IDevicePresenter* presenter )
{
	std::unique_ptr<IDevice> device = std::make_unique<DigitalDevice>( name, presenter, this->getIdGenerator() );
	return device;
}

std::unique_ptr<DigitalDeviceVariantA> DigitalDeviceFactory::createVariantA( const std::string& name, IDevicePresenter* presenter )
{

	return std::make_unique<DigitalDeviceVariantA>( name, presenter, this->getIdGenerator(), this->_randomizer );
}
std::unique_ptr<DigitalDeviceVariantB> DigitalDeviceFactory::createVariantB( const std::string& name, IDevicePresenter* presenter )
{
	return std::make_unique<DigitalDeviceVariantB>( name, presenter, this->getIdGenerator() );
}
std::unique_ptr<DigitalDeviceVariantC> DigitalDeviceFactory::createVariantC( const std::string& name, IDevicePresenter* presenter )
{
	return std::make_unique<DigitalDeviceVariantC>( name, presenter, this->getIdGenerator(), _strategies );
}
