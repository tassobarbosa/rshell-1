cc = g++ //compiler
flags = -Wall -Werror -ansi -pedantic /flags


all: rshell

rshell: if [ ! -d bin/ ]; then mkdir bin; fi
		  $(cc) $(flags) src/main.cpp -o bin/rshell
