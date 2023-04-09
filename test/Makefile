all: a.out
	./a.out < input

a.out: main.cpp
	g++ -g -O0 --std=c++17 -Wall -Iinclude -DLOCAL main.cpp
#	g++ -fdiagnostics-color=always -g -O0 --std=c++17 -Wall -fsanitize=undefined,address -Iinclude -DLOCAL main.cpp

clean:
	rm -f a.out
