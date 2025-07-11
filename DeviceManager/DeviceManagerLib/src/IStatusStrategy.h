#pragma once
#include <string>
#include <DigitalDevice.h>
#include <DigitalDeviceVariantC.h>
class IStatusStrategy
{
	public:
	virtual ~IStatusStrategy() = default;
	virtual std::string Execute( DigitalDeviceVariantC* device ) = 0;
	virtual std::string Peek(const DigitalDeviceVariantC* device ) const  = 0;
};
