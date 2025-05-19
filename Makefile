CXX=g++
# CXX=g++

# We have -Wno-unused-parameter so that the compiler
# doesn't complain too much about our stubs.

#CXXFLAGS = -std=c++17 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field

# Change to this before final submission:

CXXFLAGS = -std=c++17 -Wall -Wextra -Werror

BINARIES=lab06Test01 lab06Test02

all: ${BINARIES}

lab06Test01: lab06Test01.o WordCount.o tddFuncs.o
	${CXX} $^ -o $@

lab06Test02: lab06Test02.o WordCount.o tddFuncs.o
	${CXX} $^ -o $@

tests: ${BINARIES}
	./lab06Test01
	./lab06Test02

clean:
	/bin/rm -f ${BINARIES} *.o
