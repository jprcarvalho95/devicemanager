#include "AnalogDeviceFactory.h"
#include "AnalogDevice.h"
#include "IDevice.h"
#include "IDevicePresenter.h"
#include <memory>
std::unique_ptr<IDevice> AnalogDeviceFactory::createDevice( const std::string& name, IDevicePresenter* presenter )
{
	std::unique_ptr<IDevice> device = std::make_unique<AnalogDevice>( name, presenter, this->getIdGenerator() );
	return device;
}
