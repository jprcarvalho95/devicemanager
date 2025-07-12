#pragma once
#include "IDeviceFactory.h"
#include "AnalogDevice.h"
#include "IDevice.h"
#include <memory>
class AnalogDeviceFactory : public IDeviceFactory
{
public:
	AnalogDeviceFactory(IIDGenerator* idGenerator) : IDeviceFactory(idGenerator) {}
	std::unique_ptr<IDevice> createDevice( const std::string& name, IDevicePresenter* presenter );


};

