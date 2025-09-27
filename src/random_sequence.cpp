#include "random_sequence.h"

#include <random>
#include <vector>

RandomSequence::RandomSequence() : mt(std::random_device{}()) {}

std::vector<int> RandomSequence::operator()(const int size, const int min_value, const int max_value) {
	std::vector<int> seq(size);

	std::uniform_int_distribution<int> dist(min_value, max_value);
	for (int i = 0; i < size; i++) {
		seq[i] = dist(mt);
	}

	return seq;
}
