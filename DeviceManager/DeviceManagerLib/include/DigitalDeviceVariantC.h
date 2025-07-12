#pragma once
#include "DigitalDevice.h"
#include <unordered_map>
#include "Constants.h"
#include "IStatusStrategy.h"
#include "IIDGenerator.h"
#include "IDevicePresenter.h"

class DigitalDeviceVariantC : public DigitalDevice
{
private:
	std::unordered_map<Constants::DigitalDevice::Generation, IStatusStrategy*> _availableStrategies;
	Constants::DigitalDevice::Generation _generation;
	unsigned int _internalPercentage = 0;

public:
	DigitalDeviceVariantC(
		  std::string a_name
		, IDevicePresenter* presenter
		, IIDGenerator* idGenerator
		, std::unordered_map<Constants::DigitalDevice::Generation, IStatusStrategy*>

	);	

	std::string updateStatus();
	std::string getStatus() const override;
	std::string getDescription() const;

	int getInternalPercentage() const;

	void setInternalPercentage( int newPercentage );
	
};
