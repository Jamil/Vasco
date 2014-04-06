EXEC = vasco 
CC = g++
SRC = main.cpp 
OBJ = VSData.o VSSupervisedData.o VSBatchDescentLearner.o VSStochasticLearner.o VSLearner.o
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

VSBatchDescentLearner.o: VSBatchDescentLearner.cpp VSBatchDescentLearner.h
	$(CC) $(CFLAGS) -c VSBatchDescentLearner.cpp -o VSBatchDescentLearner.o

VSStochasticLearner.o: VSStochasticLearner.cpp VSStochasticLearner.h
	$(CC) $(CFLAGS) -c VSStochasticLearner.cpp -o VSStochasticLearner.o

clean:
	rm -f *.o 
	rm vasco 
