#include "Globals.h"

Globals* instance = nullptr;

Globals& Globals::GetInstance()
{
	if ( !instance )
	{
		instance = new Globals();
	}
	return *instance;
}

unsigned int Globals::GetNextFreeDeviceID()
{
	return ++m_nextFreeId;
}
