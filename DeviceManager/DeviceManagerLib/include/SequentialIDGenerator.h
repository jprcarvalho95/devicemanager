#pragma once
#include "IIDGenerator.h"
#include "IDevice.h"
class SequentialIDGenerator :public IIDGenerator
{

private:
	unsigned int _minId;
	unsigned int _maxId;
	unsigned int _currentId;
public:
	SequentialIDGenerator(unsigned int minId, unsigned int maxId);	
	unsigned int getNextFreeId() override;
	unsigned int getMaxId() const override;
};

