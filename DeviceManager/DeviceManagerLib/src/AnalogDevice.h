#pragma once
#include "Device.h"
class AnalogDevice : public Device
{
	AnalogDevice(std::string a_name, IDevicePresenter* presenter);
	std::string getDevicePrefix() const override;
};

