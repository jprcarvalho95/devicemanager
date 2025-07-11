#pragma once
#include <string>
#include <IDevice.h>
#include <DigitalDevice.h>
class IDevicePresenter {
public:
 	virtual ~IDevicePresenter() = default;

	//Set functions as purely virtual to provide interface behavior
	virtual void PresentDeviceName(const IDevice& device) = 0;
	virtual void PresentDeviceID(const IDevice& device) = 0;
	virtual void PresentDeviceDescription(const IDevice& device) = 0;
	virtual void PresentDeviceStatus( const DigitalDevice& device ) = 0;
};
