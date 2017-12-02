#include <iostream>
#include "perceptron.hpp"
#include <functional>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "andTrainer.hpp"
#include "orTrainer.hpp"
#include "greaterTrainer.hpp"
#include "greaterThanTrainer.hpp"
#include "equalityTrainer.hpp"
#include "lessThanTrainer.hpp"
#include <cmath>

using namespace std;

float activator(float a) {
	if(a>1) return 1;
	else return 0;
}

float randomizer() {
	return rand() % 3 - 1;
}

int main() {
	srand(time(NULL));
	function<float()> randomizerFunc = randomizer;
	function<float(float)> activatorFunc = activator;
	Perceptron brain(3, randomizerFunc, activatorFunc);
	AndTrainer andTrainer(1000);
	andTrainer.learn(brain);
	cout<<"And Training: "<<andTrainer.errorLevel(brain)<<"\%"<<endl;
	OrTrainer orTrainer(1000);
	orTrainer.learn(brain);
	cout<<"Or Training: "<<orTrainer.errorLevel(brain)<<"\%"<<endl;
	EqualityTrainer equalityTrainer(20000);
	equalityTrainer.learn(brain);
	cout<<"Equality Training: "<<equalityTrainer.errorLevel(brain)<<"\%"<<endl;
	GreaterThanTrainer greaterThanTrainer(15000);
	greaterThanTrainer.learn(brain);
	cout<<"Greater Than Training: "<<greaterThanTrainer.errorLevel(brain)<<"\%"<<endl;
	LessThanTrainer lessThanTrainer(15000);
	lessThanTrainer.learn(brain);
	cout<<"Less Than Training: "<<lessThanTrainer.errorLevel(brain)<<"\%"<<endl;

	Perceptron brain2(2, randomizerFunc, activatorFunc);
	GreaterTrainer greaterTrainer(10000);
	greaterTrainer.learn(brain2);
	cout<<"Greater Training: "<<greaterTrainer.errorLevel(brain2)<<"\%"<<endl;
	return 0;
}