#pragma once
namespace Constants {
	namespace AnalogDevice
	{
		constexpr int MIN_ID = 100;
		constexpr int MAX_ID = 9999;
		constexpr std::string_view PREFIX = "AD";
	}
	namespace DigitalDevice
	{
		enum class Variant
		{
			VariantA,
			VariantB,
			VariantC
		};
		constexpr int MIN_ID = 10000;
		constexpr int MAX_ID = 19999;
		constexpr std::string_view PREFIX = "DD";

	}
}
