#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include "inqumath.h"

class Perceptron {
private:
	double output;
	double delta;
	double sum;
	std::vector<double> weight;
	std::vector<double> inputs;
public:
	Perceptron();
	void secChangeWeight(double ideal);
	void changeWeight(double ideal);
	double process(std::vector<double> v);
	double getOutput();

};

#endif