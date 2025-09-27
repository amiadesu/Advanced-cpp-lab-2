#include <cmath>

namespace testing {
	double sigmoid(const int x) {
		return 1 / (1 + std::exp(-x));
	}

	bool isSigmoidMoreThanHalf(const int x) {
		return sigmoid(x) > 0.5;
	}
}
