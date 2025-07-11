#pragma once
#include <IStatusStrategy.h>
#include <DigitalDeviceVariantC.h>
class StrategyGen1 : public IStatusStrategy
{
	// Inherited via IStatusStrategy
	std::string Execute( DigitalDeviceVariantC* device ) override;
	std::string Peek(const DigitalDeviceVariantC* device ) const override;

};
