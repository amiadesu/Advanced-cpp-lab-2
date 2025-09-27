#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>
#include <functional>
#include <chrono>

#include "constants.h"
#include "random_sequence.h"
#include "testing_func.h"

using namespace std;
#include "timeit.h"

bool check_function(int x) {
	return testing::isSigmoidMoreThanHalf(x);
}

template <typename Iterator>
bool process_block(Iterator first, Iterator last, const function<bool(int)>& f)
{
	return none_of(first, last, f);
}

template <typename Iterator>
bool parallel_algorithm(Iterator first, Iterator last, size_t K, const function<bool(int)>& f)
{
	size_t length = std::distance(first, last);
	if (length == 0) {
		return true;
	}

	size_t block_size = (length + K - 1) / K;

	// vector<int> instead of vector<bool>, therefore we will keep only 1 or 0 in it
	vector<int> results(K, 1);
	vector<thread> threads;

	Iterator block_start = first;
	for (size_t i = 0; i < K; ++i) {
		Iterator block_end = (i == K - 1) ? last : block_start + min(block_size, (size_t)distance(block_start, last));

		threads.emplace_back(
			[block_start, block_end, &results, i, &f]() {
				results[i] = process_block(block_start, block_end, f);
			}
		);

		block_start = block_end;
		if (block_start == last) {
			break;
		}
	}

	for (auto& t : threads) {
		t.join();
	}

	return none_of(results.begin(), results.end(), [](bool v) { return !v; });
}

void part3(const vector<int>& numbers)
{
	cout << "\n\nPart 3" << endl;

	auto best_time = chrono::system_clock::duration::max();
	size_t best_K = constants::MIN_K;

	for (size_t K = constants::MIN_K; K <= constants::MAX_K; K++) {
		bool result = false;
		cout << "K = " << K << ":          ";
		auto elapsed = timeit(
			[&numbers, &result, &K]() {
				result = parallel_algorithm(numbers.cbegin(), numbers.cend(), K, check_function);
			}, constants::REPEAT_TIMES
		);
		cout << "result = " << result << endl;

		if (elapsed < best_time) {
			best_time = elapsed;
			best_K = K;
		}
	}

	cout << "Best K = " << best_K << " with time ";
	if (best_time > 100000ns)
		cout << format("{:%S}", best_time) << endl << endl;
	else
		cout << best_time << endl << endl;
}
