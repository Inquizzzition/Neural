#ifndef NETWORK_H
#define NETWORK_H

#include "perceptron.h"

class Network {
private:
	std::vector<std::vector<Perceptron>> perceptrones;
	std::vector<int> layersSize;
public:
	Network();
	void addFirstLayer(int LayerSize, int inputs);
	void addLayer(int LayerSize);
	void popLastLayer();
	std::vector<double> go(std::vector<double> inputs);
};

#endif