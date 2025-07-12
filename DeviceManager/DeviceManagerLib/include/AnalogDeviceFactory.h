#pragma once
#include "IDeviceFactory.h"
#include "AnalogDevice.h"
#include "IDevice.h"
class AnalogDeviceFactory : public IDeviceFactory
{
public:
	AnalogDeviceFactory(IIDGenerator* idGenerator) : IDeviceFactory(idGenerator) {}
	IDevice* createDevice( const std::string& name, IDevicePresenter* presenter );


};

