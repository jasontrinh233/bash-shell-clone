all: command

command: command.o tokenizer.o
	g++ -std=c++11 command.o tokenizer.o -o command -lreadline -lcurses

command.o: command.cpp tokenizer.hpp
	g++ -std=c++11 -c command.cpp

tokenizer.o: tokenizer.hpp tokenizer.cpp
	g++ -std=c++11 -c tokenizer.cpp
