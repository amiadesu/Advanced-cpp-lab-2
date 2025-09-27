#pragma once

namespace constants {
	inline constexpr int SEQUENCE_LENGTHS[4] = {
		1'000,
		10'000,
		100'000, 
		1'000'000
	};
	inline constexpr int MIN_SEQUENCE_VALUE = INT_MIN;
	inline constexpr int MAX_SEQUENCE_VALUE = 0;
	inline constexpr size_t MIN_K = 1;
	inline constexpr size_t MAX_K = 32;
	inline constexpr int REPEAT_TIMES = 10;
}