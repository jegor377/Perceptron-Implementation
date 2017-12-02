#include "../../headers/perceptron/perceptron.hpp"
#include "../../headers/perceptron/weightsAndInputsSizesNotEqual.hpp"

Perceptron::Perceptron(
	int weightsAmount,
	std::function<float()>& randomProductFunc,
	std::function<float(float)> activationFunc) {
	while(weightsAmount--) {
		this->weights.push_back(randomProductFunc());
	}
	this->activationFunc = activationFunc;
}

Perceptron::~Perceptron() {
	this->weights.clear();
}

float Perceptron::feedForward(std::vector<float>& inputs) {
	if(this->weights.size() == inputs.size()) {
		float sum = 0;
		for(int i=0; i<this->weights.size(); i++) {
			sum += inputs[i] * this->weights[i];
		}
		return this->activationFunc(sum);
	}
	throw WeightsAndInputsSizesNotEqual();
}

void Perceptron::train(
	std::vector<float>& inputs,
	float desiredOutput,
	float learningRate) {
	if(this->weights.size() == inputs.size()) {
		float guessOutput = this->feedForward(inputs);
		float errorOutput = desiredOutput - guessOutput;

		for(int i=0; i<this->weights.size(); i++) {
			this->weights[i] += learningRate * errorOutput * inputs[i];
		}
	} else throw WeightsAndInputsSizesNotEqual();
}