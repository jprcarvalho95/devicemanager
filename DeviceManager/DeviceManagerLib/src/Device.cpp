#include <iostream>

#include "Device.h"
#include "Globals.h"
#include <iomanip>
#include <sstream> 
Device::Device( std::string a_name, IDevicePresenter* presenter)
	: m_name( a_name )
	, _presenter( presenter )
{
	m_id = Globals::GetInstance().GetNextFreeDeviceID();
}

void Device::printInfo() const
{
	if ( _presenter != nullptr)
	{
		_presenter->PresentDeviceName( *this );
		_presenter->PresentDeviceID( *this );
		_presenter->PresentDeviceDescription( *this );
	}
}

std::string Device::getName() const
{
	return this->m_name;
}

unsigned int Device::getDeviceID() const
{
	return this->m_id;
}

std::string Device::getDescription() const
{
	std::ostringstream oss;
	// Calculate the length of the maxId to set the width for formatting
	oss << std::setw(
			   std::to_string( this->maxId ).length() )
		<< std::setfill( '0' ) << this->getDeviceID();

	return oss.str();
}
