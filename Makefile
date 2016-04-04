# Makefile

CC = g++
CFLAGS = -g -Wall 

all: main.out

main.out: main.o craps.o player.o dice.o 
	$(CC) $(CFLAGS) -o main.out main.o craps.o player.o dice.o 

main.o: main.cpp craps.h player.h dice.h
	$(CC) -c $(CFLAGS) main.cpp 

craps.o: craps.cpp craps.h player.h dice.h
	$(CC) -c $(CFLAGS) craps.cpp

dice.o: dice.cpp dice.h
	$(CC) -c $(CFLAGS) dice.cpp

player.o: player.cpp player.h
	$(CC) -c $(CFLAGS) player.cpp 

run:
	main.out 

clean:
	rm -f *.o *~ core main.out 
