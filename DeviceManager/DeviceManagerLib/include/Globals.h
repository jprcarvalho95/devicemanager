#pragma once
class Globals
{
	Globals() = default;

	unsigned int m_nextFreeId;

public:
	static Globals& GetInstance();

	unsigned int GetNextFreeDeviceID();
};
