#include <DigitalDevice.h>
#include <DigitalDeviceFactory.h>

IDevice* DigitalDeviceFactory::createDevice( const std::string& name, IDevicePresenter* presenter )
{
	return new DigitalDevice( name, presenter, this->getIdGenerator() );
}
