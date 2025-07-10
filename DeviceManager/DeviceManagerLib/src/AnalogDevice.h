#pragma once
#include "Device.h"
class AnalogDevice : public Device
{
public:
	AnalogDevice( std::string a_name, IDevicePresenter* presenter );
	std::string getDevicePrefix() const override;
};

