#pragma once
#include "IDeviceFactory.h"
#include "DigitalDeviceVariantA.h"
#include "DigitalDeviceVariantB.h"
#include <unordered_map>
#include "Constants.h"
#include "IStatusStrategy.h"
#include "DigitalDeviceVariantC.h"
#include "IRandomizer.h"

class DigitalDeviceFactory : public IDeviceFactory
{

private:

	// Assuming every created device will use the same randomizer
	IRandomizer* _randomizer;
	std::unordered_map<Constants::DigitalDevice::Generation, IStatusStrategy*> _strategies;

public:
	DigitalDeviceFactory(
		  IIDGenerator* idGenerator
		, IRandomizer* randomizer, std::unordered_map<Constants::DigitalDevice::Generation, IStatusStrategy*> strategies)
		: IDeviceFactory( idGenerator )
	{
		_randomizer = randomizer;
		_strategies = strategies;
			
	}

	IDevice* createDevice( const std::string& name, IDevicePresenter* presenter ) override;

	DigitalDeviceVariantA* createVariantA( const std::string& name, IDevicePresenter* presenter);
	DigitalDeviceVariantB* createVariantB( const std::string& name, IDevicePresenter* presenter);
	DigitalDeviceVariantC* createVariantC( const std::string& name, IDevicePresenter* presenter);
};
