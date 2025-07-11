#include <StandardDigitalSequentialIDGenerator.h>
#include <Constants.h>
StandardDigitalSequentialIDGenerator::StandardDigitalSequentialIDGenerator()
	: SequentialIDGenerator(Constants::DigitalDevice::MIN_ID, Constants::DigitalDevice::MAX_ID)
{
}
