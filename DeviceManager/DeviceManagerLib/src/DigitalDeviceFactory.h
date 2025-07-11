#pragma once
#include "IDeviceFactory.h"
#include <DigitalDeviceVariantA.h>
#include <DigitalDeviceVariantB.h>
class DigitalDeviceFactory : public IDeviceFactory
{

private:

	// Assuming every created device will use the same randomizer
	IRandomizer* _randomizer;

public:
	DigitalDeviceFactory( IIDGenerator* idGenerator, IRandomizer* randomizer )
		: IDeviceFactory( idGenerator )
	{
		_randomizer = randomizer;
	}

	IDevice* createDevice( const std::string& name, IDevicePresenter* presenter ) override;

	DigitalDeviceVariantA* createVariantA( const std::string& name, IDevicePresenter* presenter);
	DigitalDeviceVariantB* createVariantB( const std::string& name, IDevicePresenter* presenter );
};
