all: a.out
	time ./a.out < input

a.out: main.cpp
	g++ -Wall -g -DDEBUG main.cpp

clean:
	rm -f a.out

sub:
	@g++ -Wall main.cpp
	@./a.out < input

subtime:
	@time ./a.out main.rb < input
