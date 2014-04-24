EXEC = vasco 
CC = g++
SRC = main.cpp 
OBJ = Data.o SupervisedData.o BatchDescentLearner.o StochasticLearner.o Learner.o Cluster.o
CFLAGS = -Werror -g -ggdb
LDFLAGS = 

all: vasco

vasco: $(OBJ) $(SRC)
	$(CC) $(CFLAGS) $(OBJ) $(SRC) -o $(EXEC)

Data.o: Data.cpp Data.h
	$(CC) $(CFLAGS) -c Data.cpp -o Data.o

SupervisedData.o: SupervisedData.cpp SupervisedData.h
	$(CC) $(CFLAGS) -c SupervisedData.cpp -o SupervisedData.o

Learner.o: Learner.cpp Learner.h
	$(CC) $(CFLAGS) -c Learner.cpp -o Learner.o

BatchDescentLearner.o: BatchDescentLearner.cpp BatchDescentLearner.h
	$(CC) $(CFLAGS) -c BatchDescentLearner.cpp -o BatchDescentLearner.o

StochasticLearner.o: StochasticLearner.cpp StochasticLearner.h
	$(CC) $(CFLAGS) -c StochasticLearner.cpp -o StochasticLearner.o

Cluster.o: Cluster.cpp Cluster.h
	$(CC) $(CFLAGS) -c Cluster.cpp -o Cluster.o

clean:
	rm -f *.o 
	rm vasco 
