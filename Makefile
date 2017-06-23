CC=clang++
CXXFLAGS=-std=c++14
OBJ=main.o table.o game.o fsm.o
DEP=table.h constants.h fsm.h
BIN=main

exec: $(BIN)
	./$^

$(BIN): $(OBJ)
	$(CC) $(CXXFLAGS) -o $@ $^

%.o: %.cpp $(DEP)
	$(CC) $(CXXFLAGS) -c -o $@ $<

clear:
	rm $(OBJ) $(BIN)
