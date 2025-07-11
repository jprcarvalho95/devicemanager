#pragma once
#include <random>
#include "IRandomizer.h"
class StandardRandomizer : public IRandomizer
{
private:
	// Mersenne Twister generator

	std::mt19937 _gen;

public:
	StandardRandomizer();

	// Inherited via IRandomizer
	float getRandomFloat( float min, float max );

};
