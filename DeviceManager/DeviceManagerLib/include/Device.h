#pragma once

#include <string>
#include <IDevicePresenter.h>
#include <IIDGenerator.h>

class Device : public IDevice
{
public:
	Device( std::string a_name, IDevicePresenter* presenter, IIDGenerator* idGenerator );
	void printInfo() const;
	// Inherited via IDevice
	std::string getName() const override;
	std::string getDescription() const override;
	unsigned int getDeviceID() const override;

private:
	IDevicePresenter* _presenter; 
	std::string m_name;

protected:
	unsigned int m_id = 0;
	unsigned int paddingSize = 0;
	std::string devicePrefix ;
};
