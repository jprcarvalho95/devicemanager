// Copyright © Schueco Digital GmbH 2023
// @Author: Konstantin Nikkel

#include <vector>

#include "Device.h"
#include "AnalogDevice.h"
#include "DefaultDevicePresenter.h"
#include <memory>

std::vector<std::unique_ptr<Device>> generateData( size_t count, IDevicePresenter* presenter )
{
	std::vector<std::unique_ptr<Device>> result;

	for ( size_t current = 0; current < count; ++current )
	{
		const std::string deviceName = "device " + std::to_string( current );
		const std::string desc = "this is dev no " + std::to_string( current );

		auto device = AnalogDevice( deviceName, presenter );
		result.push_back( std::make_unique<AnalogDevice>( deviceName, presenter ) );

 	}
	return result;
}

void showData( const std::vector<std::unique_ptr<Device>>& devices )
{
	for ( const auto& device : devices )
	{
		device->printInfo();
	}
}

int main()
{

	constexpr size_t dataToGenerate = 5;
	std::vector<std::unique_ptr<Device>>  devices = generateData( dataToGenerate, new DefaultDevicePresenter() );
	showData( devices );

}
