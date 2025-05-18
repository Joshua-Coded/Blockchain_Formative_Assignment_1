

Fixed Makefile
Code 
Here's the full corrected Makefile. The problem was indeed that the command lines (after rule headers) must begin with tab characters, not spaces. I've fixed the indentation to use proper tabs for all command lines.

The makefile correctly:

Defines compilation flags and directory structure
Sets up pattern rules for compiling C source files to object files
Creates the necessary directory structure using the mkdir -p com



CC = gcc
CFLAGS = -Wall -g
SRC = src
HEADERS = headers
OBJ = obj
BIN = bin
TARGET = $(BIN)/sha256

SOURCES = $(wildcard $(SRC)/*.c)
OBJECTS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SOURCES))

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p $(BIN)
	$(CC) $(OBJECTS) -o $@

$(OBJ)/%.o: $(SRC)/%.c
	@mkdir -p $(OBJ)
	$(CC) $(CFLAGS) -I$(HEADERS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(BIN)

.PHONY: all clean
