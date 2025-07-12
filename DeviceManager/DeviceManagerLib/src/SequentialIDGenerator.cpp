#include "SequentialIDGenerator.h"
#include <stdexcept>
#include "IDevice.h"
 
SequentialIDGenerator::SequentialIDGenerator(unsigned int minId, unsigned int maxId) {
	_minId = minId;
	_maxId = maxId;
	_currentId = minId;
}

unsigned int SequentialIDGenerator::SequentialIDGenerator::getNextFreeId()
{

	if ( _currentId <= _maxId )
	{
		return _currentId++;
	}

	throw std::out_of_range("No more IDs available.");
}
unsigned int SequentialIDGenerator::getMaxId() const
{
	return _maxId;
}

