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
std::vector<std::unique_ptr<IDevice>> generateData( size_t count
	, IDevicePresenter* presenter
	, AnalogDeviceFactory* analogFactory
	, DigitalDeviceFactory* digitalFactory)
{
	std::vector<std::unique_ptr<IDevice>> result;

	for ( size_t current = 0; current < count; ++current )
	{
		const std::string deviceName = "Device " + std::to_string( current );

		IDevice* analogDevice1 = analogFactory->createDevice( deviceName, presenter );
		IDevice* digitalDevice1 = digitalFactory->createDevice( deviceName, presenter );
		IDevice* digitalDeviceVariantA = digitalFactory->createVariantA( deviceName, presenter );
		IDevice* digitalDeviceVariantB = digitalFactory->createVariantB( deviceName, presenter );
		IDevice* digitalDeviceVariantC = digitalFactory->createVariantC( deviceName, presenter );


 	}
	return result;
}

void showData( const std::vector<std::unique_ptr<IDevice>>& devices )
{
	for ( const auto& device : devices )
	{
		device->printInfo();
	}
}

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

	//IDevice* device1 = analogFactory->createDevice( "Analog Device 1", new DefaultDevicePresenter() );
	//device1->printInfo();
	//for ( int i = 0; i < 100; i++ )
	//{
	//	analogFactory->createDevice( "Analog Device " + std::to_string( i ), new DefaultDevicePresenter() )->printInfo();	 
	//}
	//for ( int i = 0; i < 100; i++ )
	//{
	//	digitalFactory->createDevice( "Digital Device " + std::to_string( i ), new DefaultDevicePresenter() )->printInfo();
	//}

	//for (int i = 0; i < 100; i++ )
	//{
	//	digitalFactory->createVariantC( "Digital Device Variant C" + std::to_string( i ), new DefaultDevicePresenter() )->printInfo();
	//}

	constexpr size_t dataToGenerate = 5;
	std::vector<std::unique_ptr<IDevice>>  devices = generateData( dataToGenerate
		, new DefaultDevicePresenter()
		, analogFactory
		, digitalFactory
	);
	showData( devices );

}
