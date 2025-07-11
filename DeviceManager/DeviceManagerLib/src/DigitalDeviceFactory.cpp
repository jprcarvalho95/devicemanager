#include <DigitalDevice.h>
#include <DigitalDeviceFactory.h>

IDevice* DigitalDeviceFactory::createDevice( const std::string& name, IDevicePresenter* presenter )
{
	return new DigitalDevice( name, presenter, this->getIdGenerator() );
}

DigitalDeviceVariantA* DigitalDeviceFactory::createVariantA( const std::string& name, IDevicePresenter* presenter )
{
	return new DigitalDeviceVariantA( name, presenter, this->getIdGenerator(), this->_randomizer );
}
DigitalDeviceVariantB* DigitalDeviceFactory::createVariantB( const std::string& name, IDevicePresenter* presenter )
{
	return new DigitalDeviceVariantB( name, presenter, this->getIdGenerator());
}
