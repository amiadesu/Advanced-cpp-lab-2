#pragma once

#include <random>
#include <vector>

class RandomSequence {
private:
	std::mt19937 mt;

public:
	RandomSequence();
	std::vector<int> operator()(const int size, const int min_value = INT_MIN, const int max_value = INT_MAX);
};