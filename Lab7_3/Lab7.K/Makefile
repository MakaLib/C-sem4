CXX=g++
CXXFLAGS=-Wall -Wextra -pedantic -g
FNAME=Algebra
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o) 

all : $(FNAME)

$(FNAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $? -o $@

$(OBJ) : $(SRC)
	$(CXX)  -c $(CXXFLAGS) $*.cpp -o $@



clean:
	rm -rf $(FNAME) *.o

rr: clean all

mem:
	valgrind --log-fd=1 ./$(FNAME)| grep "lost"

new:
	  @read -p  "Nazwa nowej klasy: " module; \
	touch $$module.h $$module.cpp; \
	echo "#pragma once" > $$module.h
