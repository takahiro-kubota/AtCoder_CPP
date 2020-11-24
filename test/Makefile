all: a.out
	./a.out < input

a.out: main.cpp
	g++ -std=c++17 -Wall -g -I../ac-library main.cpp

clean:
	rm -f a.out
