// Copyright © Schueco Digital GmbH 2023
// @Author: Konstantin Nikkel

#include <vector>
#include <SequentialIDGenerator.h>
#include "Device.h"
#include "AnalogDevice.h"
#include "DefaultDevicePresenter.h"
#include <memory>
#include <AnalogDeviceFactory.h>
#include <DigitalDeviceFactory.h>

//std::vector<std::unique_ptr<Device>> generateData( size_t count, IDevicePresenter* presenter, AnalogDeviceFactory* factory )
//{
//	std::vector<std::unique_ptr<Device>> result;
//
//	for ( size_t current = 0; current < count; ++current )
//	{
//		const std::string deviceName = "device " + std::to_string( current );
//		const std::string desc = "this is dev no " + std::to_string( current );
//
//		auto device = factory->createDevice( deviceName, presenter );
//		result.push_back( std::make_unique<AnalogDevice>( deviceName, presenter ) );
//		   
// 	}
//	return result;
//}

//void showData( const std::vector<std::unique_ptr<Device>>& devices )
//{
//	for ( const auto& device : devices )
//	{
//		device->printInfo();
//	}
//}

int main()
{
	AnalogDeviceFactory* analogFactory = new AnalogDeviceFactory( new SequentialIDGenerator(100,9999) );
	DigitalDeviceFactory* digitalFactory = new DigitalDeviceFactory( new SequentialIDGenerator(10000,19999) );
	IDevice* device1 = analogFactory->createDevice( "Analog Device 1", new DefaultDevicePresenter() );
	device1->printInfo();
	for ( int i = 0; i < 100; i++ )
	{
		analogFactory->createDevice( "Analog Device " + std::to_string( i ), new DefaultDevicePresenter() )->printInfo();	 
	}
	//constexpr size_t dataToGenerate = 5;
	//std::vector<std::unique_ptr<Device>>  devices = generateData( dataToGenerate, new DefaultDevicePresenter() );
	//showData( devices );

}
