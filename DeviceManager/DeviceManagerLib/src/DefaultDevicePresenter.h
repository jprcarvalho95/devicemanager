#include "IDevicePresenter.h"
class DefaultDevicePresenter : public IDevicePresenter
{
	DefaultDevicePresenter();

	// Inherited via IDevicePresenter
	void PresentDeviceName(const IDevice& device) override;
	void PresentDeviceID(const IDevice& device) override;
	void PresentDeviceDescription(const IDevice& device) override;
};
