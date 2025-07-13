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
void DefaultDevicePresenter::printInfo( const IDevice& device )
{
	std::cout << " - Device Name: " << device.getName() << "\n";
	std::cout << " - Device Id: " << device.getDeviceID() << "\n";
	std::cout << " - Device Description: " << device.getDescription() << "\n";
}

void DefaultDevicePresenter::printInfo( const DigitalDevice& device )
{
	const IDevice& baseDevice = device;
	DefaultDevicePresenter::printInfo( baseDevice );

	std::cout << " - Device Status: " + device.getStatus() + "\n";
}
