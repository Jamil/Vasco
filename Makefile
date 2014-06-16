EXEC = kmeans-test-1 kmeans-test-2
CC = g++
SRC = main.cpp 
OBJ = Data.o SupervisedData.o BatchDescentLearner.o StochasticLearner.o Learner.o Cluster.o
CFLAGS = -Werror -g -ggdb
LDFLAGS = -lreadline

lib: $(OBJ)
tests: kmeans

###############
# THE LIBRARY #
###############

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

#################
# K-MEANS TESTS #
#################

kmeans: KMeansTest1 KMeansTest2 
KMEANS = Cluster.o SupervisedData.o Data.o

KMeansTest1: test-kmeans-1.cpp
	$(CC) $(CFLAGS) test-kmeans-1.cpp $(KMEANS) -o kmeans-test-1

KMeansTest2: test-kmeans-2.cpp
	$(CC) $(CFLAGS) test-kmeans-2.cpp $(KMEANS) -o kmeans-test-2

#########
# CLEAN #
#########

clean:
	rm -f *.o 
	rm $(EXEC)
