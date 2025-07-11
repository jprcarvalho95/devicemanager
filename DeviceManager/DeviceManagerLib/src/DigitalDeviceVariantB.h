#pragma once
#include "DigitalDevice.h"
class DigitalDeviceVariantB : public DigitalDevice
{
private:
	bool _internalStatus = false;

public:
	DigitalDeviceVariantB( std::string a_name, IDevicePresenter* presenter, IIDGenerator* idGenerator );
	std::string getStatus() const override;
	std::string updateStatus();
};
