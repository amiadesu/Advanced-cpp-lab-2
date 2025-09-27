#include <iostream>
#include <vector>
#include <functional>
#include <execution>
#include <algorithm>

#include "constants.h"
#include "random_sequence.h"
#include "testing_func.h"

using namespace std;
#include "timeit.h"

void part2(const vector<int>& numbers)
{
	cout << "\n\nPart 2" << endl;

	auto f = [](int x)
	{
		return testing::isSigmoidMoreThanHalf(x);
	};

	bool result = false;

	cout << "none_of, seq                    ";
	timeit(
		[&numbers, &result, &f]()
		{
			result = none_of(execution::seq, numbers.begin(), numbers.end(), f);
		}, constants::REPEAT_TIMES
	);
	cout << "result = " << result << endl;

	cout << "none_of, parallel               ";
	timeit(
		[&numbers, &result, &f]()
		{
			result = none_of(execution::par, numbers.begin(), numbers.end(), f);
		}, constants::REPEAT_TIMES
	);
	cout << "result = " << result << endl;

	cout << "none_of, unsequenced            ";
	timeit(
		[&numbers, &result, &f]()
		{
			result = none_of(execution::unseq, numbers.begin(), numbers.end(), f);
		}, constants::REPEAT_TIMES
	);
	cout << "result = " << result << endl;

	cout << "none_of, parallel unsequenced   ";
	timeit(
		[&numbers, &result, &f]()
		{
			result = none_of(execution::par_unseq, numbers.begin(), numbers.end(), f);
		}, constants::REPEAT_TIMES
	);
	cout << "result = " << result << endl;
}