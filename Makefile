

SRC_DIR = src
OBJ_DIR = obj
SRCS = src/main.c src/eke.c
OBJS = obj/main.o obj/eke.o
BIN_FILE = ./eke
DEPS = inc/eke.h

CC=gcc
CFLAGS = -std=c99 -O3 -Iinc

all: directories bin tests

bin: $(OBJS)
	$(CC) -o $(BIN_FILE) $(OBJS) 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: tests clean

tests: 
	make -f ./unittests.mk

clean:
	rm -rf $(OBJ_DIR)
	rm $(BIN_FILE)
	make -f ./unittests.mk clean


directories: $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

