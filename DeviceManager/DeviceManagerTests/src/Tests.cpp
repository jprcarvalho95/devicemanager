#include "AnalogDeviceFactory.h"
#include "AnalogSequentialIdGenerator.h"
#include "Constants.h"
#include "DefaultDevicePresenter.h"
#include "DigitalDeviceFactory.h"
#include "Fakes.cpp"
#include "SequentialIDGenerator.h"
#include "StandardDigitalSequentialIDGenerator.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "StrategyGen2.h"
#include "StrategyGen1.h"
using namespace testing;


TEST( IdGeneratorTests, GivenANullIdGenerator_WhenADeviceIsCreated_AnExceptionIsThrown )
{

	AnalogDeviceFactory* factory = new AnalogDeviceFactory( nullptr );
	EXPECT_THROW( factory->createDevice( "Analog Device 1", new DefaultDevicePresenter() );, std::invalid_argument );
}
TEST( PresenterTests, GivenANullDevicePresenter_WhenAPrintInfoRequestIsMade_AnExceptionIsThrown )
{

	AnalogDeviceFactory* factory = new AnalogDeviceFactory( new StandardAnalogSequentialIDGenerator );
	auto device = factory->createDevice( "Analog Device 1", nullptr );
	EXPECT_THROW( device->printInfo(), std::runtime_error );
}
TEST( DeviceTests_Analog, GivenAnAnalogDevice_WhenAnIDIsAssigned_ThenItShouldBeWithinDefinedDomain100_9999 )
{
	AnalogDeviceFactory* factory = new AnalogDeviceFactory( new StandardAnalogSequentialIDGenerator() );
	auto device = factory->createDevice( "Analog Device 1", new DefaultDevicePresenter() );
	EXPECT_THAT( device->getDeviceID(), AllOf( Ge( Constants::AnalogDevice::MIN_ID ), Le( Constants::AnalogDevice::MAX_ID ) ) );
}

TEST( DeviceTests_Analog, GivenAnAnalogDevice_WhenAPrefixIsRequested_ThenTheDefaultAnalogPrefixShouldBeReturned )
{
	AnalogDeviceFactory* factory = new AnalogDeviceFactory( new StandardAnalogSequentialIDGenerator );
	auto device = factory->createDevice( "Analog Device 1", new DefaultDevicePresenter() );
	std::string prefix = device->getDevicePrefix();
	EXPECT_THAT( prefix, Eq( std::string( Constants::AnalogDevice::PREFIX ) ) );
}

TEST( DeviceTests_Digital_VariantA, GivenADigitalDeviceVariantA_WhenTheInternalStatusIsMin_ReturnLow )
{


	float fakeRandomValue = Constants::DigitalDevice::MIN_STATUS;

	// This chunk of code shouold be in a global test environment setup method
	// but for simplicity I kept it here, this applies to all tests in this file

	std::string expectedValue = std::string { Constants::DigitalDevice::LOW };
	std::unordered_map<Constants::DigitalDevice::Generation, IStatusStrategy*> strategies;

	DigitalDeviceFactory* factory = new DigitalDeviceFactory(
		new StandardDigitalSequentialIDGenerator(), new FakeRandomizer( fakeRandomValue ), strategies );

	auto device = factory->createVariantA( "Digital Device Variant A 1", new DefaultDevicePresenter() );
	EXPECT_EQ( device->getStatus(), expectedValue );
}


TEST( DeviceTests_Digital_VariantA, GivenADigitalDeviceVariantA_WhenTheInternalStatusIsMaxed_ReturnHigh )
{
	float fakeRandomValue = Constants::DigitalDevice::MAX_STATUS;
	std::string expectedValue = std::string { Constants::DigitalDevice::HIGH };

	std::unordered_map<Constants::DigitalDevice::Generation, IStatusStrategy*> strategies;

	DigitalDeviceFactory* factory = new DigitalDeviceFactory(
		new StandardDigitalSequentialIDGenerator(), new FakeRandomizer( fakeRandomValue ), strategies );

	auto device = factory->createVariantA( "Digital Device Variant A 1", new DefaultDevicePresenter() );
	EXPECT_EQ( device->getStatus(), expectedValue );
}

TEST( DeviceTests_Digital_VariantA, GivenADigitalDeviceVariantA_WhenTheInternalStatusIsWithinBounds_ReturnInternalStatus )
{
	float expectedValue = 25.0f;
	std::unordered_map<Constants::DigitalDevice::Generation, IStatusStrategy*> strategies;

	DigitalDeviceFactory* factory = new DigitalDeviceFactory(
		new StandardDigitalSequentialIDGenerator(), new FakeRandomizer( expectedValue ), strategies );

	auto device = factory->createVariantA( "Digital Device Variant A 1", new DefaultDevicePresenter() );
	EXPECT_EQ( device->getStatus(), "25.0" );
}
TEST( DeviceTests_Digital_VariantB, GivenANewDigitalDeviceVariantB_WhenTheInternalStatusIsRequested_ReturnOff )
{
	std::string expectedValue = std::string { Constants::DigitalDevice::OFF };


	std::unordered_map<Constants::DigitalDevice::Generation, IStatusStrategy*> strategies;

	DigitalDeviceFactory* factory = new DigitalDeviceFactory(
		new StandardDigitalSequentialIDGenerator(), new FakeRandomizer( 1 ),
		strategies );

	auto device = factory->createVariantB( "Digital Device Variant B 1", new DefaultDevicePresenter() );

	EXPECT_EQ( device->getStatus(), expectedValue );
}

TEST( DeviceTests_Digital_VariantB, GivenANewDigitalDeviceVariantB_WhenTheInternalStatusIsUpdated_ReturnOn )
{
	std::string expectedValue = std::string { Constants::DigitalDevice::ON };

	std::unordered_map<Constants::DigitalDevice::Generation, IStatusStrategy*> strategies;

	DigitalDeviceFactory* factory = new DigitalDeviceFactory(
		new StandardDigitalSequentialIDGenerator(), new FakeRandomizer( 1 ),
		strategies );

	auto device = factory->createVariantB( "Digital Device Variant B 1", new DefaultDevicePresenter() );
	device->updateStatus();
	EXPECT_EQ( device->getStatus(), expectedValue );
}

TEST( DeviceTests_Digital_VariantB, GivenADigitalDeviceVariantB_WhenTheInternalStatusIsOff_ReturnOff )
{
	std::string expectedValue = std::string { Constants::DigitalDevice::OFF };
	std::unordered_map<Constants::DigitalDevice::Generation, IStatusStrategy*> strategies;

	DigitalDeviceFactory* factory = new DigitalDeviceFactory(
		new StandardDigitalSequentialIDGenerator(), new FakeRandomizer( 1 ), strategies );

	auto device = factory->createVariantB( "Digital Device Variant B 1", new DefaultDevicePresenter() );
	// This flips the internal status
	device->getStatus();

	EXPECT_EQ( device->getStatus(), expectedValue );
}

TEST( DeviceTests_Digital_VariantC, GivenANewDigitalDeviceVariantC_WhenTheDescriptionIsRequested_ThenReturnDefaultDescription )
{

	int fakeID = 10000; // This ID is below the threshold for Gen2

	std::string expectedValue = std::string { Constants::DigitalDevice::PREFIX } + std::to_string( fakeID );

	std::unordered_map<Constants::DigitalDevice::Generation, IStatusStrategy*> strategies;
	strategies.insert( { Constants::DigitalDevice::Generation::Gen1, new StrategyGen1() } );

	DigitalDeviceFactory* factory = new DigitalDeviceFactory(
		new FakeIdGenerator( fakeID, Constants::DigitalDevice::MAX_ID ), new FakeRandomizer( 1 ), strategies );

	auto device = factory->createVariantC( "Digital Device Variant C 1", new DefaultDevicePresenter() );

	EXPECT_EQ( device->getDescription(), expectedValue );
}
TEST( DeviceTests_Digital_VariantC, GivenANewDigitalDeviceVariantCGen2_WhenTheDescriptionIsRequested_ThenAppendedDescription )
{

	int fakeID = 17000; // This ID is above the threshold for Gen2

	std::string expectedValue =
		std::string { Constants::DigitalDevice::PREFIX } + std::to_string( fakeID ) + std::string { Constants::DigitalDevice::GEN2_OUTPUT_MODIFIER };

	std::unordered_map<Constants::DigitalDevice::Generation, IStatusStrategy*> strategies;
	strategies.insert( { Constants::DigitalDevice::Generation::Gen1, new StrategyGen1() } );

	DigitalDeviceFactory* factory = new DigitalDeviceFactory(
		new FakeIdGenerator( fakeID, Constants::DigitalDevice::MAX_ID ), new FakeRandomizer( 1 ), strategies );

	auto device = factory->createVariantC( "Digital Device Variant C 1 GEN 2", new DefaultDevicePresenter() );

	EXPECT_EQ( device->getDescription(), expectedValue );
}
TEST( DeviceTests_Digital_VariantC, GivenANewDigitalDeviceVariantCGen2_WhenTheStatusIsUpdated_Then1PercentIsAdded)
{

	int fakeID = 17000; // This ID is above the threshold for Gen2

	std::string expectedValue =
		std::string { Constants::DigitalDevice::PREFIX } + std::to_string( fakeID ) + std::string { Constants::DigitalDevice::GEN2_OUTPUT_MODIFIER };

	std::unordered_map<Constants::DigitalDevice::Generation, IStatusStrategy*> strategies;
	strategies.insert( { Constants::DigitalDevice::Generation::Gen2, new StrategyGen2() } );

	DigitalDeviceFactory* factory = new DigitalDeviceFactory(
		new FakeIdGenerator( fakeID, Constants::DigitalDevice::MAX_ID ), new FakeRandomizer( 1 ), strategies );

	auto device = factory->createVariantC( "Digital Device Variant C 1 GEN 2", new DefaultDevicePresenter() );

	auto originalStatus = device->getStatus();
	auto updatedStatus = device->updateStatus();

	EXPECT_EQ( originalStatus, std::string { Constants::DigitalDevice::OPENED } );
	EXPECT_EQ( updatedStatus, "1%" );
}
