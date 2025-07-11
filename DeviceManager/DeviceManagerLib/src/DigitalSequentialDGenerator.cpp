#include "DigitalSequentialIDGenerator.h"
#include "Constants.h"

DigitalSequentialDGenerator::DigitalSequentialDGenerator()
	: SequentialIDGenerator( Constants::DigitalDevice::MIN_ID, Constants::DigitalDevice::MAX_ID )
{
}

