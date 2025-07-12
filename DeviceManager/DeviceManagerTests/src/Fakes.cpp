#include "IIDGenerator.h"
#include "IRandomizer.h"
#include "IStatusStrategy.h"
class FakeRandomizer : public IRandomizer
{
private:
	float _fixedValue;

public:
	FakeRandomizer( float fixedValue )
		: _fixedValue( fixedValue )
	{
	}
	float getRandomFloat( float min, float max ) override
	{
		return _fixedValue;
	}
};

class FakeStrategy : public IStatusStrategy
{
public:
	FakeStrategy( std::string fakeExecute, std::string fakePeek )
		: _fakeExecute( fakeExecute )
		, _fakePeek( fakePeek )
	{
	}

private:
	std::string _fakeExecute;
	std::string _fakePeek;

	// Inherited via IStatusStrategy
	std::string Execute( DigitalDeviceVariantC* device ) override
	{
		return _fakeExecute;
	}
	std::string Peek( const DigitalDeviceVariantC* device ) const override
	{
		return _fakePeek;
	}
};

class FakeIdGenerator : public IIDGenerator
{
private:
	int _fakeID;
	int _fakeMaxID;

public:
	FakeIdGenerator( int fakeID, int fakeMaxID )
	{
		_fakeID = fakeID;
		_fakeMaxID = fakeMaxID;
	}

	// Inherited via IIDGenerator
	unsigned int getNextFreeId() override
	{
		return this->_fakeID;
	}
	unsigned int getMaxId() const override
	{
		return this->_fakeMaxID;
	}
};
