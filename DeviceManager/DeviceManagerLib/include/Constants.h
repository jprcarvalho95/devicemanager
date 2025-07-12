#pragma once
#include <string_view>
namespace Constants {
	namespace AnalogDevice
	{
		constexpr int MIN_ID = 100;
		constexpr int MAX_ID = 9999;
		constexpr std::string_view PREFIX = "AD";
	}
	namespace DigitalDevice
	{
		enum class Generation{
			Gen1,
			Gen2
		};
		enum class Variant
		{
			VariantA,
			VariantB,
			VariantC
		};
		constexpr int MIN_ID = 10000;
		constexpr int MAX_ID = 19999;
		const float MIN_STATUS = -50.0f;
		const float MAX_STATUS = 70.0f;
		constexpr std::string_view PREFIX = "DD";
		constexpr std::string_view ON = "On";
		constexpr std::string_view OFF = "Off";
		constexpr std::string_view LOW = "Low";
		constexpr std::string_view HIGH = "High";
		constexpr std::string_view GEN2_OUTPUT_MODIFIER = "(Gen 2)";
		constexpr std::string_view OPENED = "Opened";
		constexpr std::string_view CLOSED = "Closed";

	}
}
