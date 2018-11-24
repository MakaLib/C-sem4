CXX=g++
CXXFLAGS=-Wall
CXXFLAGS+=-g
CXXFLAGS+=-Wextra
CXXFLAGS+=-pedantic -std=c++11

SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)

all: Fraction

Fraction: $(OBJ)
	$(CXX) $(CXXLAGS) $? -o $@

$(OBJ): $(SRC)
	$(CXX) $(CXXFLAGS) -c $*.cpp -o $@

.PHONY: clean

clean:
	rm -f Fraction $(OBJ)
	
run: Fraction
	./Fraction
