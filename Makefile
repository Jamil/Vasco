EXEC = vasco 
CC = g++
SRC = main.cpp 
OBJ = VSData.o VSBatchDescentLearner.o VSStochasticLearner.o VSLearner.o
CFLAGS = -Werror -g -ggdb
LDFLAGS = 

all: vasco

vasco: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(SRC) -o $(EXEC)

VSData.o: VSData.cpp 
	$(CC) $(CFLAGS) -c VSData.cpp -o VSData.o

VSLearner.o: VSLearner.cpp
	$(CC) $(CFLAGS) -c VSLearner.cpp -o VSLearner.o

VSBatchDescentLearner.o: VSBatchDescentLearner.cpp
	$(CC) $(CFLAGS) -c VSBatchDescentLearner.cpp -o VSBatchDescentLearner.o

VSStochasticLearner.o: VSStochasticLearner.cpp
	$(CC) $(CFLAGS) -c VSStochasticLearner.cpp -o VSStochasticLearner.o

clean:
	rm -f *.o 
	rm vasco main
