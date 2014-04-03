all: vasco

vasco: VSData.o VSBatchDescentLearner.o VSStochasticLearner.o VSLearner.o 
	g++ VSData.o VSBatchDescentLearner.o VSStochasticLearner.o VSLearner.o main.cpp -o vasco

VSData.o:
	g++ -c VSData.cpp -o VSData.o

VSBatchDescentLearner.o: VSLearner.o 
	g++ -c VSBatchDescentLearner.cpp -o VSBatchDescentLearner.o

VSStochasticLearner.o: VSLearner.o 
	g++ -c VSStochasticLearner.cpp -o VSStochasticLearner.o

VSLearner.o:
	g++ -c VSLearner.cpp -o VSLearner.o

clean:
	rm -f *.o
