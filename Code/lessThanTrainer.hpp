#ifndef LESS_THAN_TRAINER_H
#define LESS_THAN_TRAINER_H

#include "trainer.hpp"
#include "perceptron.hpp"
#include <cstdlib>

class LessThanTrainer
	: public Trainer
{
public:
	LessThanTrainer(int n)
		: Trainer(n)
	{
		;
	}

	virtual void learn(Perceptron& brain, float learningRate = 0.3) {
		auto i = this->n;
		float x = 0;
		float y = 0;
		while(i--) {
			auto answer = 0;
			x = (rand() + (int)x) % 100;
			y = (rand() + (int)y) % 100;
			if(x < y) {
				answer = 1;
			}
			std::vector<float> inputs = {x, y, 1};
			brain.train(inputs, answer, learningRate);
		}
	}

	virtual float errorLevel(Perceptron& brain) {
		float goodAnswers = 0;
		float badAnswers = 0;
		auto i = this->n;
		float x = 0;
		float y = 0;
		while(i--) {
			auto answer = 0;
			x = (rand() + (int)x) % 100;
			y = (rand() + (int)y) % 100;
			if(x < y) {
				answer = 1;
			}
			std::vector<float> inputs = {x, y, 1};
			if(brain.feedForward(inputs) == answer) {
				goodAnswers++;
			} else {
				badAnswers++;
			}
		}
		return goodAnswers / (goodAnswers+badAnswers) * 100;
	}
};

#endif