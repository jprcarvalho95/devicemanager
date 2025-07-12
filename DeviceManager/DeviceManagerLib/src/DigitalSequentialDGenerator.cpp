#include "DigitalSequentialIDGenerator.h"
#include "Constants.h"
#include "SequentialIDGenerator.h"

DigitalSequentialIDGenerator::DigitalSequentialIDGenerator()
	: SequentialIDGenerator( Constants::DigitalDevice::MIN_ID, Constants::DigitalDevice::MAX_ID )
{
}

