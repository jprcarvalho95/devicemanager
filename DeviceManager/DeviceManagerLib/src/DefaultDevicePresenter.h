#include <IDevicePresenter.h>
#include <IDevice.h>
class DefaultDevicePresenter : public IDevicePresenter 
{
public:

	DefaultDevicePresenter();
	
// Inherited via IDevicePresenter
	void PresentDeviceName( const IDevice& device ) override;

	void PresentDeviceID( const IDevice& device ) override;

	void PresentDeviceDescription( const IDevice& device ) override;

	void PresentDeviceStatus(const DigitalDevice& device ) override;

};
