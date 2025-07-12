#include "DefaultDevicePresenter.h"
#include <iostream>
#include <iomanip>
#include "IDevice.h"
#include "DigitalDevice.h"
#include "IDevicePresenter.h"
DefaultDevicePresenter::DefaultDevicePresenter()
	: IDevicePresenter()
{
}

void DefaultDevicePresenter::PresentDeviceName(const IDevice& device)
{
	std::cout << " - " << device.getName() << "\n";
}

void DefaultDevicePresenter::PresentDeviceID(const IDevice& device)
{
	std::cout << " - " << device.getDeviceID() << "\n";
}

void DefaultDevicePresenter::PresentDeviceDescription(const IDevice& device)
{
	std::cout << " - " << device.getDescription() << "\n";
}

