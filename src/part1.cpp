#include <iostream>
#include <algorithm>

#include "constants.h"
#include "random_sequence.h"
#include "testing_func.h"

using namespace std;
#include "timeit.h"

void part1(const vector<int>& numbers)
{
    cout << "\n\nPart 1" << endl;

	auto f = [](int x)
	{ 
		return testing::isSigmoidMoreThanHalf(x); 
	};

	bool result = false;

	cout << "none_of, no policy              ";
	timeit(
		[&numbers, &result, &f]()
		{ 
			result = none_of(numbers.begin(), numbers.end(), f); 
		}, constants::REPEAT_TIMES
	);
	cout << "result = " << result << endl;
}
