#ifndef INQUMATH_H
#define INQUMATH_H

#include <vector>
#include <cmath>
#include <random>

const double DELTA = 0.01;

double activation(double x);

double dActivation(double x);

double dot(std::vector<double> a, std::vector<double> b);
#endif // !INQUMATH_H
