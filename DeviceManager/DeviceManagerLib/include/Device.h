#pragma once

#include <string>

class Device
{
public:
	Device( std::string a_name, std::string a_description );

	void printInfo() const;

private:
	unsigned int m_id;

	std::string m_name;
	std::string m_description;
};
