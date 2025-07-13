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
#include <iostream>
std::vector<std::unique_ptr<IDevice>> generateData( size_t count
	, IDevicePresenter* presenter
	, AnalogDeviceFactory* analogFactory
	, DigitalDeviceFactory* digitalFactory)
{
	std::vector<std::unique_ptr<IDevice>> result;

	for ( size_t current = 0; current < count; ++current )
	{
		const std::string deviceName = " Device " + std::to_string( current );

		std::unique_ptr<IDevice> analogDevice1 = analogFactory->createDevice( "Analog " + deviceName, presenter );
		std::unique_ptr<IDevice> digitalDevice1 = digitalFactory->createDevice( "Digital " + deviceName, presenter );
		std::unique_ptr<IDevice> digitalDeviceVariantA = digitalFactory->createVariantA( "Digital Variant A" + deviceName, presenter );
		std::unique_ptr<IDevice> digitalDeviceVariantB = digitalFactory->createVariantB( "Digital Variant B" + deviceName, presenter );
		std::unique_ptr<IDevice> digitalDeviceVariantC = digitalFactory->createVariantC( "Digital Variant C" + deviceName, presenter );
		result.push_back( std::move( analogDevice1 ) );
		result.push_back( std::move( digitalDevice1 ) );
		result.push_back( std::move( digitalDeviceVariantA ) );
		result.push_back( std::move( digitalDeviceVariantB ) );
		result.push_back( std::move( digitalDeviceVariantC ) );	

 	}
	return result;
}

void showData( const std::vector<std::unique_ptr<IDevice>>& devices )
{
	for ( const auto& device : devices )
	{
		device->printInfo();
		std::cout << "----------------------------------------\n";
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

	constexpr size_t dataToGenerate = 5;
	std::vector<std::unique_ptr<IDevice>>  devices = generateData( dataToGenerate
		, new DefaultDevicePresenter()
		, analogFactory
		, digitalFactory
	);
	showData( devices );

}
