OBJ = '/obj'

all: cube.o main.cpp Cubie.o Matrix.o
	g++ -g Matrix.o cube.o Cubie.o main.cpp -o rubik -lglut -lGL

cube.o: cube.cpp cube.h
	g++ -g -c cube.cpp -o cube.o

Cubie.o: Cubie.cpp Cubie.h
	g++ -g -c Cubie.cpp -o Cubie.o

Matrix.o: Matrix.h Matrix.cpp
	g++ -g -c Matrix.cpp -o Matrix.o