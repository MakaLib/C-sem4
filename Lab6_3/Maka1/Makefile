CXX=g++
CXXFLAGS=-Wall
CXXFLAGS+=-g
CXXFLAGS+=-Wextra
CXXFLAGS+=-pedantic

SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)

all: Arrays

Arrays: $(OBJ)
	$(CXX) $(CXXLAGS) $? -o $@

$(OBJ): $(SRC)
	$(CXX) $(CXXFLAGS) -c $*.cpp -o $@

.PHONY: clean

clean:
	rm -f Arrays $(OBJ)
	
run: Arrays
	./Arrays
