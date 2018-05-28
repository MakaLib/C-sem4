CXX=g++
CXXFLAGS=-Wall
CXXFLAGS+=-g -std=c++11


SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)

all: SmartPointer

SmartPointer: $(OBJ)
	$(CXX) $(CXXLAGS) $? -o $@

$(OBJ): $(SRC)
	$(CXX) $(CXXFLAGS) -c $*.cpp -o $@

.PHONY: clean

clean:
	rm -f SmartPointer $(OBJ)
	
run: SmartPointer
	./SmartPointer
