BIN=processpol
CC=c++
FlAGS=-c -Wall -std=c++11
LDFLAGS=-o
SRC=$(wildcard *.cc)
OBJ=$(SRC:.cc=.o)

$(BIN):$(OBJ)
	$(CC) $(LDFLAGS) $@ $^
%.o:%.cc
	$(CC) $(FlAGS) $<

.PHONY:clean
clean:
	rm -rf $(BIN) $(OBJ)
.PHONY:test
test:
	@echo $(BIN)
	@echo $(OBJ)