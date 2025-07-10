#pragma once

#include <string>
#include "IDevice.h"
#include <IDevicePresenter.h>
class Device : IDevice
{
public:
	Device( std::string a_name, IDevicePresenter* presenter );

	void printInfo() const;
	// Inherited via IDevice
	std::string getName() const override;
	std::string getDescription() const override;
	unsigned int getDeviceID() const override;
private:
	IDevicePresenter* _presenter; 
	unsigned int m_id;

	std::string m_name;

protected:
	unsigned int minId;
	unsigned int maxId;
	std::string devicePrefix ;
};
