#include "AnalogSequentialIDGenerator.h"

StandardAnalogSequentialIDGenerator::StandardAnalogSequentialIDGenerator()
	: SequentialIDGenerator( Constants::AnalogDevice::MIN_ID, Constants::AnalogDevice::MAX_ID )
{
}
