#ifndef PERCEPTRON_TRAINER_H
#define PERCEPTRON_TRAINER_H

#include "../perceptron/perceptron.hpp"

class PerceptronTrainer {
protected:
	int feedBackwardRepeatCount;

public:
	PerceptronTrainer(int feedBackwardRepeatCount);

	virtual void train(Perceptron& perceptron, float learningRate = 0.1) = 0;
};

#endif