#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <AnalogDeviceFactory.h>
#include <SequentialIDGenerator.h>
#include <DefaultDevicePresenter.h>
#include <Constants.h>
#include <AnalogSequentialIdGenerator.h>
// Demonstrate some basic assertions.
using namespace testing;
TEST( DeviceTests,  GivenAnAnalogDevice_WhenAnIDIsAssigned_ThenItShouldBeWithinDefinedDomain100_9999 )
{
	AnalogDeviceFactory* factory = new AnalogDeviceFactory( new StandardAnalogSequentialIDGenerator() );
	auto device = factory->createDevice( "Analog Device 1", new DefaultDevicePresenter() );
	EXPECT_THAT( device->getDeviceID(), AllOf( Ge( Constants::AnalogDevice::MIN_ID ), Le( Constants::AnalogDevice::MAX_ID) ) );
}

TEST( DeviceTests, GivenANullIdGenerator_WhenADeviceIsCreated_AnExceptionIsThrown ) {

	AnalogDeviceFactory* factory = new AnalogDeviceFactory( nullptr );
	EXPECT_THROW( factory->createDevice( "Analog Device 1", new DefaultDevicePresenter() );, std::invalid_argument );
}
TEST( DeviceTests, GivenANullDevicePresenter_WhenAPrintInfoRequestIsMade_AnExceptionIsThrown )
{

	AnalogDeviceFactory* factory = new AnalogDeviceFactory( new StandardAnalogSequentialIDGenerator );
	auto device = factory->createDevice( "Analog Device 1", nullptr );	
	EXPECT_THROW( device->printInfo(), std::runtime_error );
}

TEST( DeviceTests, GivenAnAnalogDevice_WhenAPrefixIsRequested_ThenTheDefaultAnalogPrefixShouldBeReturned)
{
	AnalogDeviceFactory* factory = new AnalogDeviceFactory( new StandardAnalogSequentialIDGenerator );
	auto device = factory->createDevice( "Analog Device 1", new DefaultDevicePresenter() );
	std::string prefix = device->getDevicePrefix();
	EXPECT_THAT( prefix, Eq( std::string( Constants::AnalogDevice::PREFIX )));	
}
