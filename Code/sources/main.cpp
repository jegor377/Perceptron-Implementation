#include <iostream>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <vector>
#include "../headers/perceptron/perceptron.hpp"
#include "../headers/perceptron/weightsAndInputsSizesNotEqual.hpp"
#include "../headers/perceptronTrainer/trainers/perceptronAndTrainer.hpp"

using namespace std;

const auto LEARNING_REPEAT_COUNT = 1000;
const auto WEIGHTS_COUNT = 2;

// simple activation function for perceptron. Similar to https://en.wikipedia.org/wiki/Heaviside_step_function
float activationFunc(float value) {
	return (value > 1 ? 1 : 0);
}

// returns random number from -1 to 1
float randomProductFunc() {
	return rand() % 3 - 1;
}

void askUserForInputs() {
	cout<<"Program made by Igor Santarek. MIT License 2017."<<endl<<endl;
	cout<<"Type two binary digits: ";
}

// binary number can be 0 or 1 only.
bool isBinaryNumber(float number) {
	return (number == 0 || number == 1 ? true : false);
}

// asks user to input two binary digits till the inputs aren't binary.
std::vector<float> getInputsFromUser() {
	std::vector<float> result = {0, 0};
	float firstBinary = -1;
	float secondBinary = -1;
	while( !(isBinaryNumber(firstBinary) && isBinaryNumber(secondBinary)) ) {
		askUserForInputs();
		cin>>firstBinary>>secondBinary;
		result[0] = firstBinary;
		result[1] = secondBinary;
		cout<<endl;
	}
	return result;
}

void returnToUserFeedForwardResult(Perceptron& perceptron, std::vector<float>& inputs) {
	try {
		cout<<"The AND result is: "<<perceptron.feedForward(inputs)<<endl;
	} catch(WeightsAndInputsSizesNotEqual& ex) {
		cout<<ex.what()<<endl;
	}
}

int main() {
	// giving seed value to random function.
	srand(time(NULL));

	std::function<float()> _randomProductFunc = randomProductFunc;
	std::function<float(float)> _activationFunc = activationFunc;

	Perceptron perceptron(WEIGHTS_COUNT, _randomProductFunc, _activationFunc);

	PerceptronAndTrainer trainer(LEARNING_REPEAT_COUNT);
	trainer.train(perceptron);

	auto inputs = getInputsFromUser();
	returnToUserFeedForwardResult(perceptron, inputs);
	return 0;
}