#ifndef OR_TRAINER_H
#define OR_TRAINER_H

#include "trainer.hpp"
#include "perceptron.hpp"
#include <vector>
#include <array>

class OrTrainer
	: public Trainer
{
	std::vector< std::vector<float>> problems;
public:
	OrTrainer(int n)
		: Trainer(n)
	{
		problems = {
			{0, 0, 0},
			{1, 1, 1},
			{0, 1, 1},
			{1, 0, 1}
		};
	}

	virtual void learn(Perceptron& brain, float learningRate = 0.3) {
		auto i = this->n;
		while(i--) {
			for(int i=0; i<4; i++) {
				auto answer = problems[i][2];
				std::vector<float> inputs = {problems[i][0], problems[i][1], 1};
				brain.train(inputs, answer, learningRate);
			}
		}
	}

	virtual float errorLevel(Perceptron& brain) {
		float goodAnswers = 0;
		float badAnswers = 0;
		auto i = this->n;
		while(i--) {
			for(int i=0; i<4; i++) {
				auto answer = problems[i][2];
				std::vector<float> inputs = {problems[i][0], problems[i][1], 1};
				if(brain.feedForward(inputs) == answer) {
					goodAnswers++;
				} else {
					badAnswers++;
				}
			}
		}
		return goodAnswers / (goodAnswers+badAnswers) * 100;
	}
};

#endif