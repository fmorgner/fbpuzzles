CC=g++
LDFLAGS=-lstdc++
CFLAGS=-I.

all: gattaca	

gattaca : main.o prediction.o utility.o
	${CC} ${LDFLAGS} -o gattaca main.o prediction.o utility.o

main.o: main.cxx
	${CC} ${CFLAGS} -c main.cxx

utility.o: utility.cxx
	${CC} ${CFLAGS} -c utility.cxx

prediction.o: Prediction.cxx
	${CC} ${CFLAGS} -c Prediction.cxx

clean:
	rm *.o
	rm gattaca

