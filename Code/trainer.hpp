#ifndef TRAINER_H
#define TRAINER_H

class Trainer {
protected:
	int n;
public:
	Trainer(int n) {
		this->n = n;
	}

	virtual void learn(Perceptron& brain, float learningRate = 0.3) = 0;
	virtual float errorLevel(Perceptron& brain) = 0;
};

#endif