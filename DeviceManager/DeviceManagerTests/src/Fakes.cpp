#include "IRandomizer.h"
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
