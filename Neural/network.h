#ifndef NETWORK_H
#define NETWORK_H

#include "perceptron.h"

class Network {
private:
	int inputSize;
	std::vector<std::vector<Perceptron>> perceptrones;
	std::vector<int> layersSize;
public:
	Network();
	void addFirstLayer(int LayerSize, int inputs);
	void addLayer(int LayerSize);
	void popLastLayer();
	std::vector<double> go(std::vector<double> inputs);
	void learning(std::vector<double> ideal);
};

#endif