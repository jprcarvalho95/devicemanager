#include "Device.h"
#include "IDevice.h"
#include "IDevicePresenter.h"
#include "IIDGenerator.h"
#include <iomanip>
#include <iostream>
#include <sstream>

Device::Device( std::string a_name, IDevicePresenter* presenter, IIDGenerator* idGenerator )
	: m_name( a_name )
	, _presenter( presenter )
{

	if ( idGenerator == nullptr )
	{
		throw std::invalid_argument( "IDGenerator cannot be null" );
	}

	if ( _presenter == nullptr )
	{
		throw std::invalid_argument( "Presenter is not set. Cannot print device info." );
	}

	m_id = idGenerator->getNextFreeId();
	paddingSize = idGenerator->getMaxId();
}

void Device::printInfo() const
{
	_presenter->printInfo( *this );
}

std::string Device::getName() const
{
	return this->m_name;
}

unsigned int Device::getDeviceID() const
{
	return this->m_id;
}

std::string Device::getDevicePrefix() const
{
	return std::string();
}


std::string Device::getDescription() const
{
	std::ostringstream oss;
	// Calculate the length of the maxId to set the width for formatting
	oss << std::setw(
			   std::to_string( this->paddingSize ).length() )
		<< std::setfill( '0' ) << this->getDeviceID();

	return this->getDevicePrefix() + oss.str();
}
