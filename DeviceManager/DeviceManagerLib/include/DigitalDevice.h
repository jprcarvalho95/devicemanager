#pragma once
#include "Device.h"
class DigitalDevice : public Device
{
public:

	DigitalDevice( std::string a_name, IDevicePresenter* presenter, IIDGenerator* idGenerator );	
	void printInfo() const override;
	std::string getDevicePrefix() const;
	virtual std::string getStatus() const;
	std::string updateStatus();
};


