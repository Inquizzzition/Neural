#include "inqumath.h"

double activation(double x) {
	return 1 / (1 + exp(-x));
}

double dActivation(double x) {
	return activation(x) * (1 - activation(x));
}

double dot(std::vector<double> a, std::vector<double> b) {
	double sum = 0;
	for (int i = 0; i < a.size(); i++) {
		sum += a[i] * b[i];
	}
	return sum;
}

