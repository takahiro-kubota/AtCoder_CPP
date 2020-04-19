all: a.out
	./a.out < input

a.out: main.cpp
	g++ -std=c++17 -Wall -g -DDEBUG main.cpp

clean:
	rm -f a.out
