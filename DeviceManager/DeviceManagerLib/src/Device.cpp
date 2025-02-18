#include <iostream>

#include "Device.h"
#include "Globals.h"

Device::Device( std::string a_name, std::string a_description )
	: m_name( a_name )
	, m_description( a_description )
{
	m_id = Globals::GetInstance().GetNextFreeDeviceID();
}

void Device::printInfo() const
{
	std::cout << " >>> \n";

	std::cout << " - " << m_id << "\n";
	std::cout << " - " << m_name << "\n";
	std::cout << " - " << m_description << "\n";

	std::cout << " <<< \n";
}
