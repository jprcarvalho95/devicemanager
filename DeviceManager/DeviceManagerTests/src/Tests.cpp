#include "AnalogDeviceFactory.h"
#include "AnalogSequentialIdGenerator.h"
#include "Constants.h"
#include "DefaultDevicePresenter.h"
#include "DigitalDeviceFactory.h"
#include "Fakes.cpp"
#include "SequentialIDGenerator.h"
#include "StandardDigitalSequentialIDGenerator.h"
#include "StrategyGen1.h"
#include "StrategyGen2.h"
#include "array"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
using namespace testing;


TEST( IdGeneratorTests, GivenANullIdGenerator_WhenADeviceIsCreated_AnExceptionIsThrown )
{

	AnalogDeviceFactory* factory = new AnalogDeviceFactory( nullptr );
	EXPECT_THROW( factory->createDevice( "Analog Device 1", new DefaultDevicePresenter() );, std::invalid_argument );
}
TEST( PresenterTests, GivenANullDevicePresenter_WhenAPrintInfoRequestIsMade_AnExceptionIsThrown )
{

	AnalogDeviceFactory* factory = new AnalogDeviceFactory( new StandardAnalogSequentialIDGenerator );

	EXPECT_THROW( factory->createDevice( "Analog Device 1", nullptr ), std::invalid_argument );
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
	strategies.insert( { Constants::DigitalDevice::Generation::Gen2, new StrategyGen2() } );

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
	strategies.insert( { Constants::DigitalDevice::Generation::Gen2, new StrategyGen2() } );

	DigitalDeviceFactory* factory = new DigitalDeviceFactory(
		new FakeIdGenerator( fakeID, Constants::DigitalDevice::MAX_ID ), new FakeRandomizer( 1 ), strategies );

	auto device = factory->createVariantC( "Digital Device Variant C 1 GEN 2", new DefaultDevicePresenter() );

	EXPECT_EQ( device->getDescription(), expectedValue );
}
TEST( DeviceTests_Digital_VariantC, GivenANewDigitalDeviceVariantCGen2_WhenTheStatusIsUpdated_Then1PercentIsAdded )
{

	std::string opened = std::string { Constants::DigitalDevice::OPENED };
	std::string closed = std::string { Constants::DigitalDevice::CLOSED };

	// This array was auto-generated
	// instead of using a loop to generate the expected values
	// in order to make it easier to read
	std::array<std::string, 101> expectedValues {
		opened, "1%", "2%", "3%", "4%", "5%", "6%", "7%", "8%", "9%", "10%",
		"11%", "12%", "13%", "14%", "15%", "16%", "17%", "18%", "19%", "20%",
		"21%", "22%", "23%", "24%", "25%", "26%", "27%", "28%", "29%", "30%",
		"31%", "32%", "33%", "34%", "35%", "36%", "37%", "38%", "39%", "40%",
		"41%", "42%", "43%", "44%", "45%", "46%", "47%", "48%", "49%", "50%",
		"51%", "52%", "53%", "54%", "55%", "56%", "57%", "58%", "59%", "60%",
		"61%", "62%", "63%", "64%", "65%", "66%", "67%", "68%", "69%", "70%",
		"71%", "72%", "73%", "74%", "75%", "76%", "77%", "78%", "79%", "80%",
		"81%", "82%", "83%", "84%", "85%", "86%", "87%", "88%", "89%", "90%",
		"91%", "92%", "93%", "94%", "95%", "96%", "97%", "98%", "99%", closed
	};

	std::array<std::string, 101> obtainedValues;

	int fakeID = 17000; // This ID is above the threshold for Gen2

	std::unordered_map<Constants::DigitalDevice::Generation, IStatusStrategy*> strategies;
	strategies.insert( { Constants::DigitalDevice::Generation::Gen1, new StrategyGen1() } );
	strategies.insert( { Constants::DigitalDevice::Generation::Gen2, new StrategyGen2() } );

	DigitalDeviceFactory* factory = new DigitalDeviceFactory(
		new FakeIdGenerator( fakeID, Constants::DigitalDevice::MAX_ID ), new FakeRandomizer( 1 ), strategies );

	auto device = factory->createVariantC( "Digital Device Variant C 1 GEN 2", new DefaultDevicePresenter() );
	obtainedValues[0] = device->getStatus();
	for ( int i = 1; i < 101; ++i )
	{
		obtainedValues[i] = device->updateStatus();
	}

	for ( int i = 0; i < 101; ++i )
	{
		EXPECT_EQ( obtainedValues[i], expectedValues[i] );
	}
}

TEST( DeviceTests_Digital_VariantC, GivenANewDigitalDeviceVariantCGen1_WhenTheStatusIsUpdated_Then10PercentIsAdded )
{

	std::array<std::string, 11> expectedValues {
		"0%", "10%", "20%", "30%", "40%", "50%", "60%", "70%", "80%", "90%", "100%"
	};

	std::array<std::string, 11> obtainedValues;

	// This ID is below the threshold for Gen2
	int fakeID = Constants::DigitalDevice::ID_GEN1_CAP - 1;

	std::unordered_map<Constants::DigitalDevice::Generation, IStatusStrategy*> strategies;
	strategies.insert( { Constants::DigitalDevice::Generation::Gen1, new StrategyGen1() } );
	strategies.insert( { Constants::DigitalDevice::Generation::Gen2, new StrategyGen2() } );

	DigitalDeviceFactory* factory = new DigitalDeviceFactory(
		new FakeIdGenerator( fakeID, Constants::DigitalDevice::MAX_ID ), new FakeRandomizer( 1 ), strategies );

	auto device = factory->createVariantC( "Digital Device Variant C 1 GEN 2", new DefaultDevicePresenter() );

	obtainedValues[0] = device->getStatus();
	for ( int i = 1; i < 11; ++i )
	{
		obtainedValues[i] = device->updateStatus();
	}

	for ( int i = 0; i < 11; ++i )
	{
		EXPECT_EQ( obtainedValues[i], expectedValues[i] );
	}
}


TEST( DeviceTests_Digital_VariantC, GivenAClosedDigitalDeviceVariantCGen2_WhenTheStatusIsUpdated_ThenItStaysClosed )
{

	int fakeID = Constants::DigitalDevice::ID_GEN1_CAP + 1; // This ID is above the threshold for Gen2

	std::unordered_map<Constants::DigitalDevice::Generation, IStatusStrategy*> strategies;
	strategies.insert( { Constants::DigitalDevice::Generation::Gen1, new StrategyGen1() } );
	strategies.insert( { Constants::DigitalDevice::Generation::Gen2, new StrategyGen2() } );

	DigitalDeviceFactory* factory = new DigitalDeviceFactory(
		new FakeIdGenerator( fakeID, Constants::DigitalDevice::MAX_ID ), new FakeRandomizer( 1 ), strategies );

	auto device = factory->createVariantC( "Digital Device Variant C 1 GEN 2", new DefaultDevicePresenter() );
	device->setInternalPercentage( 100 ); // Set to closed state

	std::string initialStatus = device->getStatus();
	std::string updatedStatus = device->updateStatus();

	EXPECT_EQ( initialStatus, std::string{Constants::DigitalDevice::CLOSED } );
	EXPECT_EQ( initialStatus, updatedStatus );


}

TEST( DeviceTests_Digital_VariantC, GivenA100PercentDigitalDeviceVariantCGen1_WhenTheStatusIsUpdated_ThenTheStatusIs100Percent )
{

	int fakeID = Constants::DigitalDevice::ID_GEN1_CAP - 1 ; // This ID is below the threshold for Gen2

	std::unordered_map<Constants::DigitalDevice::Generation, IStatusStrategy*> strategies;
	strategies.insert( { Constants::DigitalDevice::Generation::Gen1, new StrategyGen1() } );
	strategies.insert( { Constants::DigitalDevice::Generation::Gen2, new StrategyGen2() } );

	DigitalDeviceFactory* factory = new DigitalDeviceFactory(
		new FakeIdGenerator( fakeID, Constants::DigitalDevice::MAX_ID ), new FakeRandomizer( 1 ), strategies );

	auto device = factory->createVariantC( "Digital Device Variant C 1 GEN 1", new DefaultDevicePresenter() );
	device->setInternalPercentage( 100 );

	std::string initialStatus = device->getStatus();
	std::string updatedStatus = device->updateStatus();

	EXPECT_EQ( initialStatus, "100%" );
	EXPECT_EQ( initialStatus, updatedStatus );
}
