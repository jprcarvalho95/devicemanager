#include "IRandomizer.h"
#include "IStatusStrategy.h"
class FakeRandomizer : public IRandomizer
{
private:
	float _fixedValue;
	public:
	FakeRandomizer( float fixedValue )
		: _fixedValue( fixedValue )
	{
	}
	float getRandomFloat(float min, float max) override {
		return _fixedValue;
	}
};

class FakeStrategyGen1 : public IStatusStrategy
{
	// Inherited via IStatusStrategy
	std::string Execute( DigitalDeviceVariantC* device ) override
	{
		return std::string();
	}
	std::string Peek(const DigitalDeviceVariantC* device ) const override
	{
		return std::string();
	}
};
