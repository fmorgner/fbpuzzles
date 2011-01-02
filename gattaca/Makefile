CC=g++
LDFLAGS=-lstdc++ -lm
CFLAGS=-I.

all: gattaca	

gattaca : main.o prediction.o utility.o
	${CC} ${LDFLAGS} -o gattaca main.o prediction.o utility.o

main.o: main.cxx
	${CC} ${CFLAGS} -c main.cxx

utility.o: utility.cxx
	${CC} ${CFLAGS} -c utility.cxx

prediction.o: prediction.cxx
	${CC} ${CFLAGS} -c prediction.cxx

clean:
	rm *.o
	rm gattaca
