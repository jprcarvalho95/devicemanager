#pragma once
#include "IDevice.h"
#include "IDevicePresenter.h"
#include "IIDGenerator.h"
#include <memory>
class IDeviceFactory
{
private:
	IIDGenerator* _idGenerator;

public:
	IDeviceFactory(IIDGenerator* idGenerator) : _idGenerator(idGenerator) {}
	virtual std::unique_ptr<IDevice> createDevice(const std::string& name, IDevicePresenter* presenter) = 0;

	// This should go in an abstract class instead of here, but for simplicity we keep it here
	IIDGenerator* getIdGenerator() const { return _idGenerator; }
};

