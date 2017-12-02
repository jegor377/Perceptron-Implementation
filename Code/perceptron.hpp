#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include <functional>
#include <vector>

class Perceptron {
	std::vector<float> weights;
	std::function<float(float)> activator;

public:
	Perceptron(int n, std::function<float()>& randomizer, std::function<float(float)> activator) {
		while(n--) {
			weights.push_back(randomizer());
		}
		this->activator = activator;
	}
	~Perceptron() {
		weights.clear();
	}

	float feedForward(std::vector<float>& inputs) {
		float sum = 0;
		for(auto i=0; i<weights.size(); i++) {
			sum += inputs[i] * weights[i];
		}
		return this->activator(sum);
	}

	void train(std::vector<float>& inputs, float desired, float learningRate) {
		float guess = this->feedForward(inputs);
		float error = desired - guess;
		
		for(auto i=0; i<weights.size(); i++) {
			weights[i] += learningRate * error * inputs[i];
		}
	}
};

#endif