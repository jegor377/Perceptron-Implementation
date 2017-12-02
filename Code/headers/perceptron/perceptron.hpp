#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include <functional>
#include <vector>

class Perceptron {
	std::vector<float> weights;
	std::function<float(float)> activationFunc;

public:
	Perceptron(int weightsAmount, std::function<float()>& randomProductFunc, std::function<float(float)> activationFunc);
	~Perceptron();

	// https://en.wikipedia.org/wiki/Feedforward_neural_network - asking perceptron for result of inputs.
	float feedForward(std::vector<float>& inputs);
	// https://en.wikipedia.org/wiki/Backpropagation - learning proccess for perceptron.
	void train(std::vector<float>& inputs, float desiredOutput, float learningRate);
};

#endif