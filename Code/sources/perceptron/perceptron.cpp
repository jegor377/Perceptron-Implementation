#include "../../headers/perceptron/perceptron.hpp"
#include "../../headers/perceptron/weightsAndInputsSizesNotEqual.hpp"

Perceptron::Perceptron(int weightsAmount, std::function<float()>& randomProductFunc, std::function<float(float)> activationFunc) {
	this->createWeights(weightsAmount, randomProductFunc);
	this->activationFunc = activationFunc;
}

void Perceptron::createWeights(int weightsAmount, std::function<float()>& randomProductFunc) {
	while(weightsAmount--) {
		this->weights.push_back(randomProductFunc());
	}
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

void Perceptron::train(std::vector<float>& inputs, float desired, float learningRate) {
	if(this->weights.size() == inputs.size()) {
		float guess = this->feedForward(inputs);
		float error = desired - guess;

		for(int i=0; i<this->weights.size(); i++) {
			this->weights[i] += learningRate * error * inputs[i];
		}
	} else throw WeightsAndInputsSizesNotEqual();
}