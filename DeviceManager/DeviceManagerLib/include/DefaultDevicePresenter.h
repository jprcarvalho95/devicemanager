#pragma once
#include "IDevicePresenter.h"
#include "IDevice.h"
class DefaultDevicePresenter : public IDevicePresenter 
{
public:

	DefaultDevicePresenter();
	void printInfo( const IDevice& device ) override;
	void printInfo( const DigitalDevice& device ) override;
};
