#include "network.h"
#include <iostream>
int main() {
	Perceptron p(2, 1);
	Network net;	
	net.addFirstLayer(2, 1);
	net.addLayer(6);
	net.addLayer(3);
	net.addLayer(1);

	std::vector<std::vector<double>> test(15000, std::vector<double>(2));
	std::vector<double> ideal(15000);
	for (int i = 0; i < 9500; i++) {
		test[i][0] = rand() % 10000;
		test[i][1] = rand() % 10000;
		test[i][0] /= 20000;
		test[i][1] /= 20000;
		ideal[i] = test[i][0] + test[i][1];
	}
	for (int i = 9500; i < 11000; i++) {
		test[i][0] = rand() % 100;
		test[i][1] = rand() % 100;		
		test[i][0] /= 20000;
		test[i][1] /= 20000;
		ideal[i] = test[i][0] + test[i][1];
	}
	for (int i = 11000; i < 15000; i++) {
		test[i][0] = rand() % 100 + 500;
		test[i][1] = rand() % 100 + 500;		
		test[i][0] /= 20000;
		test[i][1] /= 20000;
		ideal[i] = test[i][0] + test[i][1];
	}
	int trueans = 0;
	while (trueans < 14000) {
		trueans = 15000;
		for (int i = 0; i < 15000; i++) {
			double e = net.go(test[i])[0];
			if (abs(e-ideal[i]) > DELTA)
				trueans--;
			net.learning({ideal[i]});
		}
		std::cout << trueans << "\n";
	}
	std::cout << "learning finish\n";
	while (true) {
		double t1, t2;
		std::cin >> t1 >> t2;
		t1 /= 20000; t2 /= 20000;
		double e = net.go({ t1, t2 })[0];
		std::cout << e * 10000;
	}
}










