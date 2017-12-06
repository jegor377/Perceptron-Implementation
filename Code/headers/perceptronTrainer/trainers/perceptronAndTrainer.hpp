#ifndef PERCEPTRON_AND_TRAINER_H
#define PERCEPTRON_AND_TRAINER_H

#include <vector>
#include "../../perceptron/perceptron.hpp"
#include "../perceptronTrainer.hpp"
#include "../../perceptronProblem/perceptronProblem.hpp"

class PerceptronAndTrainer: public PerceptronTrainer{
	std::vector< PerceptronProblem > problems;
public:
	PerceptronAndTrainer(int trainingsCount);

	virtual void train(Perceptron& perceptron, float learningRate = 0.1);
private:
	void trainProblems(Perceptron& perceptron, float learningRate);
};

#endif