#pragma once
#include <string>
// Forward declaration to avoid circular dependency	
class DigitalDeviceVariantC;

class IStatusStrategy
{
	public:
	virtual ~IStatusStrategy() = default;
	virtual std::string Execute( DigitalDeviceVariantC* device ) = 0;
	virtual std::string Peek(const DigitalDeviceVariantC* device ) const  = 0;
};
