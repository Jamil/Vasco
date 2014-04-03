all: vasco

vasco: main.cpp VSData.cpp VSBatchDescentLearner.cpp VSStochasticLearner.cpp VSLearner.cpp 
	g++ VSData.cpp VSBatchDescentLearner.cpp VSStochasticLearner.cpp VSLearner.cpp main.cpp -o vasco

