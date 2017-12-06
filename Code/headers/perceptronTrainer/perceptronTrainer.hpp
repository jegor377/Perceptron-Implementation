#ifndef PERCEPTRON_TRAINER_H
#define PERCEPTRON_TRAINER_H

#include "../perceptron/perceptron.hpp"

class PerceptronTrainer {
protected:
	int trainingsCount;

public:
	PerceptronTrainer(int trainingsCount);

	virtual void train(Perceptron& perceptron, float learningRate = 0.1) = 0;
};

#endif