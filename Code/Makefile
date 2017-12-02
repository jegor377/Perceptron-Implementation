CC=g++
CFLAGS=-c
CSFLAGS=-std=c++11

SOURCES=sources/
HEADERS=headers/

WEIGHTS_AND_INPUTS_SIZES_NOT_EQUAL=$(HEADERS)perceptron/weightsAndInputsSizesNotEqual.hpp $(SOURCES)perceptron/weightsAndInputsSizesNotEqual.cpp
PERCEPTRON=$(WEIGHTS_AND_INPUTS_SIZES_NOT_EQUAL) $(HEADERS)perceptron/perceptron.hpp $(SOURCES)perceptron/perceptron.cpp

PERCEPTRON_PROBLEM=$(HEADERS)perceptronProblem/perceptronProblem.hpp

PERCEPTRON_TRAINER=$(HEADERS)perceptronTrainer/perceptronTrainer.hpp $(SOURCES)perceptronTrainer/perceptronTrainer.cpp
PERCEPTRON_AND_TRAINER=$(HEADERS)perceptronTrainer/trainers/perceptronAndTrainer.hpp $(SOURCES)perceptronTrainer/trainers/perceptronAndTrainer.cpp

main: $(SOURCES)main.cpp $(PERCEPTRON) $(PERCEPTRON_PROBLEM) $(PERCEPTRON_TRAINER) $(PERCEPTRON_AND_TRAINER)
	g++ $(SOURCES)main.cpp $(PERCEPTRON) $(PERCEPTRON_PROBLEM) $(PERCEPTRON_TRAINER) $(PERCEPTRON_AND_TRAINER) -o main

%.o: %.cpp
	$(CC) $(CFLAGS) $< $(CSFLAGS)

%.o: %.cpp $(HEADERS)%.hpp
	$(CC) $(CFLAGS) $< $(CSFLAGS)