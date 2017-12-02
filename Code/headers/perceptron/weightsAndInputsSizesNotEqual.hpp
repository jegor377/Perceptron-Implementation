#ifndef WEIGHTS_AND_INPUTS_SIZES_NOT_EQUAL_H
#define WEIGHTS_AND_INPUTS_SIZES_NOT_EQUAL_H

#include <stdexcept>

class WeightsAndInputsSizesNotEqual
	: public std::runtime_error
{
public:
	WeightsAndInputsSizesNotEqual();
};

#endif