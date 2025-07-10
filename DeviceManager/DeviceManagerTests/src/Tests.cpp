#include <gmock/gmock.h>
#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST( DeviceTests, BasicAssertions )
{
	// Expect two strings not to be equal.
	EXPECT_STRNE( "hello", "world" );
	// Expect equality.
	EXPECT_EQ( 7 * 6, 42 );
}

TEST( DeviceTests,  GivenAnAnalogDevice_WhenAnIDIsAssigned_ThenItShouldBeWithinDefinedDomain100_9999 )
{


}
