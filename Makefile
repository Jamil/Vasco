EXEC = vasco 
CC = g++
OBJ = main.o VSData.o VSBatchDescentLearner.o VSStochasticLearner.o VSLearner.o
CFLAGS = -Werror
LDFLAGS = 

all: vasco

vasco: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC)

main.o:
	g++ -c main.cpp -o main.o

VSData.o:
	g++ -c VSData.cpp -o VSData.o

VSLearner.cpp:
	g++ -c VSLearner.cpp -o VSLearner.o

VSBatchDescentLearner.o:
	g++ -c VSBatchDescentLearner.cpp -o VSBatchDescentLearner.o

VSStochasticLearner.o:
	g++ -c VSStochasticLearner.cpp -o VSStochasticLearner.o

clean:
	rm -f *.o 
	rm vasco
