#include "network.h"

Network::Network() :
	perceptrones(std::vector<std::vector<Perceptron>>(0)),
	layersSize(std::vector<int>(0))
{}

void Network::addLayer(int LayerSize) {
	std::vector<Perceptron> per(LayerSize, Perceptron(layersSize[layersSize.size()]));
	perceptrones.emplace_back(per);
	layersSize.emplace_back(LayerSize);
}

void Network::addFirstLayer(int LayerSize, int inputs) {
	std::vector<Perceptron> per(LayerSize, Perceptron(inputs));
	perceptrones.emplace_back(per);
	layersSize.emplace_back(LayerSize);
}


