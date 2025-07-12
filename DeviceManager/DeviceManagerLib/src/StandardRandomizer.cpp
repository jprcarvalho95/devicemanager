#include <random>
#include "StandardRandomizer.h"

StandardRandomizer::StandardRandomizer()
{

	// Initialize the random number generator with a random seed
	std::random_device rd;
	_gen = std::mt19937( rd() );
}
// Inherited via IRandomizer
float StandardRandomizer::getRandomFloat( float min, float max ) 
{
	std::uniform_real_distribution<float> dist( min, max );
	return dist( _gen );
}
