#pragma once
#include "DigitalDevice.h"
#include "Constants.h"
#include "IRandomizer.h"
class DigitalDeviceVariantA : public DigitalDevice
{
private:
	// Generally shouldn't be necessary define this, but for clarity
	const Constants::DigitalDevice::Variant _variant = Constants::DigitalDevice::Variant::VariantA;
	float _internalStatus = 0.0f;
	IRandomizer* _randomizer;

public:
	DigitalDeviceVariantA( std::string a_name, IDevicePresenter* presenter, IIDGenerator* idGenerator, IRandomizer* randomizer );

	std::string updateStatus();
	std::string getStatus() const override ;

};
