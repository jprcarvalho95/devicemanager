#pragma once
#include "Device.h"
class DigitalDevice : public Device
{
public:

	DigitalDevice(std::string a_name, IDevicePresenter* presenter);	
	std::string getDevicePrefix() const override;

};

