#include <AnalogDeviceFactory.h>
#include <AnalogSequentialIdGenerator.h>
#include <Constants.h>
#include <DefaultDevicePresenter.h>
#include <DigitalDeviceFactory.h>
#include <Fakes.cpp>
#include <SequentialIDGenerator.h>
#include <StandardDigitalSequentialIDGenerator.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
// Demonstrate some basic assertions.
using namespace testing;
TEST( DeviceTests, GivenAnAnalogDevice_WhenAnIDIsAssigned_ThenItShouldBeWithinDefinedDomain100_9999 )
{
	AnalogDeviceFactory* factory = new AnalogDeviceFactory( new StandardAnalogSequentialIDGenerator() );
	auto device = factory->createDevice( "Analog Device 1", new DefaultDevicePresenter() );
	EXPECT_THAT( device->getDeviceID(), AllOf( Ge( Constants::AnalogDevice::MIN_ID ), Le( Constants::AnalogDevice::MAX_ID ) ) );
}

TEST( DeviceTests, GivenANullIdGenerator_WhenADeviceIsCreated_AnExceptionIsThrown )
{

	AnalogDeviceFactory* factory = new AnalogDeviceFactory( nullptr );
	EXPECT_THROW( factory->createDevice( "Analog Device 1", new DefaultDevicePresenter() );, std::invalid_argument );
}
TEST( DeviceTests, GivenANullDevicePresenter_WhenAPrintInfoRequestIsMade_AnExceptionIsThrown )
{

	AnalogDeviceFactory* factory = new AnalogDeviceFactory( new StandardAnalogSequentialIDGenerator );
	auto device = factory->createDevice( "Analog Device 1", nullptr );
	EXPECT_THROW( device->printInfo(), std::runtime_error );
}

TEST( DeviceTests, GivenAnAnalogDevice_WhenAPrefixIsRequested_ThenTheDefaultAnalogPrefixShouldBeReturned )
{
	AnalogDeviceFactory* factory = new AnalogDeviceFactory( new StandardAnalogSequentialIDGenerator );
	auto device = factory->createDevice( "Analog Device 1", new DefaultDevicePresenter() );
	std::string prefix = device->getDevicePrefix();
	EXPECT_THAT( prefix, Eq( std::string( Constants::AnalogDevice::PREFIX ) ) );
}

TEST( DeviceTests, GivenADigitalDeviceVariantA_WhenTheInternalStatusIsMin_ReturnLow )
{
	float fakeRandomValue = -50.0f;
	std::string expectedValue = "Low";

	DigitalDeviceFactory* factory = new DigitalDeviceFactory( new StandardDigitalSequentialIDGenerator(), new FakeRandomizer( fakeRandomValue ) );

	auto device = factory->createVariantA( "Digital Device Variant A 1", new DefaultDevicePresenter() );
	EXPECT_EQ( device->getStatus(), expectedValue );
}


TEST( DeviceTests, GivenADigitalDeviceVariantA_WhenTheInternalStatusIsMaxed_ReturnHigh )
{
	float fakeRandomValue = 70.0f;
	std::string expectedValue = "High";

	DigitalDeviceFactory* factory = new DigitalDeviceFactory( new StandardDigitalSequentialIDGenerator(), new FakeRandomizer( fakeRandomValue ) );

	auto device = factory->createVariantA( "Digital Device Variant A 1", new DefaultDevicePresenter() );
	EXPECT_EQ( device->getStatus(), expectedValue );
}

TEST( DeviceTests, GivenADigitalDeviceVariantA_WhenTheInternalStatusIsWithinBounds_ReturnInternalStatus )
{
	float expectedValue = 25.0f;
	DigitalDeviceFactory* factory = new DigitalDeviceFactory( new StandardDigitalSequentialIDGenerator(), new FakeRandomizer( expectedValue ) );

	auto device = factory->createVariantA( "Digital Device Variant A 1", new DefaultDevicePresenter() );
	EXPECT_EQ( device->getStatus(), "25.0" );
}
TEST( DeviceTests, GivenADigitalDeviceVariantB_WhenTheInternalStatusIsOn_ReturnOn)
{
	std::string expectedValue = "On";

	DigitalDeviceFactory* factory = new DigitalDeviceFactory(
		new StandardDigitalSequentialIDGenerator()
		, new FakeRandomizer(1)
	);

	auto device = factory->createVariantB( "Digital Device Variant B 1", new DefaultDevicePresenter() );

	EXPECT_EQ( device->getStatus(), expectedValue );
}

TEST( DeviceTests, GivenADigitalDeviceVariantB_WhenTheInternalStatusIsOff_ReturnOff )
{
	std::string expectedValue = "Off";

	DigitalDeviceFactory* factory = new DigitalDeviceFactory(
		new StandardDigitalSequentialIDGenerator(), new FakeRandomizer( 1 ) );

	auto device = factory->createVariantB( "Digital Device Variant B 1", new DefaultDevicePresenter() );
	//This flips the internal status
	device->getStatus();

	EXPECT_EQ( device->getStatus(), expectedValue );
}
