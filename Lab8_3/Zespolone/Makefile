CXX=g++
CXXFLAGS=-Wall
CXXFLAGS+=-g
CXXFLAGS+=-Wextra
CXXFLAGS+=-pedantic
NAME = Complex

SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)

all: $(NAME)

Complex: $(OBJ)
	$(CXX) $(CXXLAGS) $? -o $@

$(OBJ): $(SRC)
	$(CXX) $(CXXFLAGS) -c $*.cpp -o $@

.PHONY: clean

clean:
	rm -f $(NAME) $(OBJ)
	
run: $(NAME)
	./$(NAME)
