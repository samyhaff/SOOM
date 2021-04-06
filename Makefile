CC=g++

FLAGS=-lSDL2 -lSDL2_image

all: SOOM.out
	./SOOM.out

clean:
	rm -f *.o SOOM.out

SOOM.out: main.o draw.o input.o init.o quit.o loadMap.o logic.o
	$(CC) $(FLAGS) -o SOOM.out main.o draw.o init.o input.o quit.o loadMap.o logic.o

draw.o: draw.cpp game.h
	$(CC) $(FLAGS) -c draw.cpp

input.o: input.cpp game.h logic.h
	$(CC) $(FLAGS) -c input.cpp

init.o: init.cpp game.h loadMap.h
	$(CC) $(FLAGS) -c init.cpp

loadMap.o: loadMap.cpp game.h
	$(CC) $(FLAGS) -c loadMap.cpp

quit.o: quit.cpp game.h
	$(CC) $(FLAGS) -c quit.cpp

logic.o: logic.cpp game.h
	$(CC) $(FLAGS) -c logic.cpp
