#pragma once
#include "Device.h"
class DigitalDevice : public Device
{
	DigitalDevice(std::string a_name, IDevicePresenter* presenter);
	
	std::string getDevicePrefix() const override;

};

