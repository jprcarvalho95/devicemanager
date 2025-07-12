#pragma once
#include "IStatusStrategy.h"

// Forward declaration to avoid circular dependency
class DigitalDeviceVariantC;

class StrategyGen2 : public IStatusStrategy
{
	std::string Execute( DigitalDeviceVariantC* device );
	std::string Peek( const DigitalDeviceVariantC* device ) const override;

};
