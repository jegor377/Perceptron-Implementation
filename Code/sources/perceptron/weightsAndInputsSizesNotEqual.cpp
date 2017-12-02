#include "../../headers/perceptron/weightsAndInputsSizesNotEqual.hpp"

WeightsAndInputsSizesNotEqual::WeightsAndInputsSizesNotEqual()
	: std::runtime_error("Weights and inputs are not the same size.")
{
	;
}