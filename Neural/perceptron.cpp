#include "perceptron.h"

Perceptron::Perceptron() :
	sum(0)
{}
void secChangeWeight(double ideal);
void changeWeight(double ideal);
double process(std::vector<double> v);
double getOutput();