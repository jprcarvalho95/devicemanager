#pragma once
#include "IDevice.h"
class IIDGenerator
{
public:
	virtual unsigned int getNextFreeId() = 0;
	virtual unsigned int getMaxId() const = 0;
};
