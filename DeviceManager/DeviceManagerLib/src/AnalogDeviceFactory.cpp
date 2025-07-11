#include "AnalogDeviceFactory.h"

IDevice* AnalogDeviceFactory::createDevice( const std::string& name, IDevicePresenter* presenter )
{
	return new AnalogDevice( name, presenter, this->getIdGenerator() );
}
