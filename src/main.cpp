#include <iostream>
#include <vector>

#include "constants.h"
#include "random_sequence.h"

using namespace std;

void part1(const vector<int>& v);
void part2(const vector<int>& v);
void part3(const vector<int>& v);

int main()
{
	using Part = void (*)(const vector<int>&);
	Part parts[] = { part1, part2, part3 };
	const size_t N = sizeof(parts) / sizeof(Part);

	cout << "This program tests if sigmoid of all of the values in a vector is not greater than a half" << endl << endl;

	RandomSequence rand_seq;

	for (auto& length : constants::SEQUENCE_LENGTHS) {
		cout << "Results for length = " << length << endl;
		auto numbers = rand_seq(
			length,
			constants::MIN_SEQUENCE_VALUE,
			constants::MAX_SEQUENCE_VALUE
		);

		for (auto& e : parts) {
			e(numbers);
		}
	}

	return 0;
}
