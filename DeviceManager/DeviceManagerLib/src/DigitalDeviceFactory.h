#pragma once
#include "IDeviceFactory.h"
class DigitalDeviceFactory : public IDeviceFactory
{
	public:
	DigitalDeviceFactory( IIDGenerator* idGenerator )
		: IDeviceFactory( idGenerator )
	{
	}

	IDevice* createDevice( const std::string& name, IDevicePresenter* presenter ) override;
 
};
