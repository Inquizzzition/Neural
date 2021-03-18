#include "network.h"

Network::Network() :
	inputSize(1),
	perceptrones(std::vector<std::vector<Perceptron>>(0)),
	layersSize(std::vector<int>(0))
{}

void Network::addLayer(int LayerSize) {
	std::vector<Perceptron> per;
	for (int i = 0; i < LayerSize; i++) {
		per.emplace_back(Perceptron(layersSize[layersSize.size() - 1], i));
	}
	perceptrones.emplace_back(per);
	layersSize.emplace_back(LayerSize);
}

void Network::addFirstLayer(int LayerSize, int inputs) {
	inputSize = inputs;
	std::vector<Perceptron> per;
	for (int i = 0; i < LayerSize; i++) {
		per.emplace_back(Perceptron(inputs, i));
	}
	perceptrones.emplace_back(per);
	layersSize.emplace_back(LayerSize);
}

void Network::popLastLayer() {
	layersSize.pop_back();
	perceptrones.pop_back();
}

std::vector<double> Network::go(std::vector<double> inputs) {
	int t = 0;
	std::vector<double> tempres;
	for (int i = 0; i < perceptrones[0].size(); i++) {
		std::vector<double> tempInp;
		for (int j = 0; j < inputSize; j++) {
			tempInp.emplace_back(inputs[t]);
			t++;
		}
		tempres.emplace_back(perceptrones[0][i].process(tempInp));
	}
	for (int i = 1; i < perceptrones.size(); i++) {
 		std::vector<double> layerRes;
		for (int j = 0; j < perceptrones[i].size(); j++) {
			layerRes.emplace_back(perceptrones[i][j].process(tempres));
		}
		tempres = layerRes;
	}
	return tempres;
}

void Network::learning(std::vector<double> ideal) {
	for (int i = 0; i < ideal.size(); i++) {
		perceptrones[perceptrones.size() - 1][i].outLayerError(ideal[i]);
		perceptrones[perceptrones.size() - 1][i].changeWeight();
	}
	//бег по слоям
	for (int i = perceptrones.size() - 2; i >= 0; i--) {
		//бег по слою 
		for (int j = 0; j < perceptrones[i].size(); j++) {
			perceptrones[i][j].zeroError(); //обнуляем ошибку перцептрона в слое
			//складывем ошибки
			for (int e = 0; e < perceptrones[1+i].size(); e++) {
				perceptrones[i][j].plusError(perceptrones[1+i][e].gerError()* perceptrones[i + 1][e].getWi(j));
			}
			perceptrones[i][j].changeWeight();
		}
		
	}
}


