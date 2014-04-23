EXEC = vasco 
CC = g++
SRC = main.cpp 
OBJ = VSData.o VSSupervisedData.o BatchDescentLearner.o StochasticLearner.o VSLearner.o Cluster.o
CFLAGS = -Werror -g -ggdb
LDFLAGS = 

all: vasco

vasco: $(OBJ) $(SRC)
	$(CC) $(CFLAGS) $(OBJ) $(SRC) -o $(EXEC)

VSData.o: VSData.cpp VSData.h
	$(CC) $(CFLAGS) -c VSData.cpp -o VSData.o

VSSupervisedData.o: VSSupervisedData.cpp VSSupervisedData.h
	$(CC) $(CFLAGS) -c VSSupervisedData.cpp -o VSSupervisedData.o

VSLearner.o: VSLearner.cpp VSLearner.h
	$(CC) $(CFLAGS) -c VSLearner.cpp -o VSLearner.o

BatchDescentLearner.o: BatchDescentLearner.cpp BatchDescentLearner.h
	$(CC) $(CFLAGS) -c BatchDescentLearner.cpp -o BatchDescentLearner.o

StochasticLearner.o: StochasticLearner.cpp StochasticLearner.h
	$(CC) $(CFLAGS) -c StochasticLearner.cpp -o StochasticLearner.o

Cluster.o: Cluster.cpp Cluster.h
	$(CC) $(CFLAGS) -c Cluster.cpp -o Cluster.o

clean:
	rm -f *.o 
	rm vasco 
