#pragma once
#include "Device.h"
class DigitalDevice : public Device
{
public:

	DigitalDevice( std::string a_name, IDevicePresenter* presenter, IIDGenerator* idGenerator );	
	std::string getDevicePrefix() const override;
	virtual std::string getStatus() const;
	std::string updateStatus();
};


