CC=gcc
LDFLAGS=-lstdc++

all: hoppity

hoppity : main.o
	${CC} ${LDFLAGS} -o hoppity main.o

main.o: main.cxx
	${CC} -c main.cxx

clean:
	rm *.o
	rm hoppity

