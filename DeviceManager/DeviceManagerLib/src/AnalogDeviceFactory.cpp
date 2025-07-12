#include "AnalogDeviceFactory.h"
#include "AnalogDevice.h"
#include "IDevice.h"
#include "IDevicePresenter.h"

IDevice* AnalogDeviceFactory::createDevice( const std::string& name, IDevicePresenter* presenter )
{
	return new AnalogDevice( name, presenter, this->getIdGenerator() );
}
