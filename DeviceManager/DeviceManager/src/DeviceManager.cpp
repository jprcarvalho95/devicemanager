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
#include <AnalogSequentialIDGenerator.h>
#include <StandardDigitalSequentialIDGenerator.h>
#include <StandardRandomizer.h>
#include <StrategyGen1.h>
#include <StrategyGen2.h>
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
	std::unordered_map<Constants::DigitalDevice::Generation, IStatusStrategy*> strategies;
	strategies.insert( { Constants::DigitalDevice::Generation::Gen1, new StrategyGen1() } );
	strategies.insert( { Constants::DigitalDevice::Generation::Gen2, new StrategyGen2() } );

	AnalogDeviceFactory* analogFactory = new AnalogDeviceFactory( new StandardAnalogSequentialIDGenerator());

	DigitalDeviceFactory* digitalFactory = new DigitalDeviceFactory(
		  new StandardDigitalSequentialIDGenerator()
		, new StandardRandomizer()
		, strategies);

	IDevice* device1 = analogFactory->createDevice( "Analog Device 1", new DefaultDevicePresenter() );
	device1->printInfo();
	for ( int i = 0; i < 100; i++ )
	{
		analogFactory->createDevice( "Analog Device " + std::to_string( i ), new DefaultDevicePresenter() )->printInfo();	 
	}
	for ( int i = 0; i < 100; i++ )
	{
		digitalFactory->createDevice( "Digital Device " + std::to_string( i ), new DefaultDevicePresenter() )->printInfo();
	}

	for (int i = 0; i < 100; i++ )
	{
		digitalFactory->createVariantC( "Digital Device Variant C" + std::to_string( i ), new DefaultDevicePresenter() )->printInfo();
	}

	//constexpr size_t dataToGenerate = 5;
	//std::vector<std::unique_ptr<Device>>  devices = generateData( dataToGenerate, new DefaultDevicePresenter() );
	//showData( devices );

}
