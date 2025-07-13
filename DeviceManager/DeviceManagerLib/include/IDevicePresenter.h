#pragma once
#include <string>
#include "IDevice.h"
class DigitalDevice;

class IDevicePresenter {
public:
 	virtual ~IDevicePresenter() = default;

	//Set functions as purely virtual to provide interface behavior
	virtual void printInfo(const IDevice& device) = 0;
	virtual void printInfo(const DigitalDevice& device ) = 0;


};
