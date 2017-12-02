#ifndef EQUALITY_TRAINER_H
#define EQUALITY_TRAINER_H

#include "trainer.hpp"
#include "perceptron.hpp"
#include <cstdlib>

class EqualityTrainer
	: public Trainer
{
public:
	EqualityTrainer(int n)
		: Trainer(n)
	{
		;
	}

	virtual void learn(Perceptron& brain, float learningRate = 0.3) {
		auto i = this->n;
		float x = 0;
		float y = 0;
		while(i--) {
			auto answer = 1;
			x = (rand() + (int)x) % 100;
			y = x;
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
			if((int)(x) % 2 == 1) {
				y = x;
				answer = 1;
			}
			std::vector<float> inputs = {x, y, 1};
			auto calculated = brain.feedForward(inputs);
			if(calculated == answer) {
				goodAnswers++;
			} else {
				badAnswers++;
			}
		}
		return goodAnswers / (goodAnswers+badAnswers) * 100;
	}
};

#endif