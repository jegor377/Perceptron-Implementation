#include "../../../headers/perceptronTrainer/trainers/perceptronAndTrainer.hpp"

PerceptronAndTrainer::PerceptronAndTrainer(int trainingsCount)
	: PerceptronTrainer(trainingsCount)
{
	this->problems = {
		PerceptronProblem{{0, 0}, 0},
		PerceptronProblem{{0, 1}, 0},
		PerceptronProblem{{1, 0}, 0},
		PerceptronProblem{{1, 1}, 1}
	};
}

void PerceptronAndTrainer::train(Perceptron& perceptron, float learningRate) {
	auto i = this->trainingsCount;
	while(i--) {
		this->trainProblems(perceptron, learningRate);
	}
}

void PerceptronAndTrainer::trainProblems(Perceptron& perceptron, float learningRate) {
	for(auto problem : this->problems) {
		perceptron.train(problem.inputs, problem.desired, learningRate);
	}
}