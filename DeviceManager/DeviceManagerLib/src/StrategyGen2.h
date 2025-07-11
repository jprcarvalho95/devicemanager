#pragma once
#include <IStatusStrategy.h>
#include <DigitalDeviceVariantC.h>
class StrategyGen2 : public IStatusStrategy
{
	std::string Execute( DigitalDeviceVariantC* device );
	std::string Peek( DigitalDeviceVariantC* device ) const override;

};
