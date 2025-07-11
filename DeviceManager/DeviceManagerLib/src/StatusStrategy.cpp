#include <IStatusStrategy.h>

class S: public IStatusStrategy
{
	// Inherited via IStatusStrategy
	std::string Execute( DigitalDevice* device ) override
	{
		return std::string();
	}
};
