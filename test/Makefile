all: a.out
	./a.out < input

a.out: main.cpp
	g++ -g -O0 --std=c++20 -Wall -Iinclude -I../ac-library -DLOCAL main.cpp
#	g++ -fdiagnostics-color=always -g -O0 --std=c++20 -Wall -fsanitize=undefined,address -Iinclude -I../ac-library -DLOCAL main.cpp

clean:
	rm -f a.out
