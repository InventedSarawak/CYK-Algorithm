# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99 -I./include
LDFLAGS = 

# Directories
SRC_DIR = src
OBJ_DIR = core
BIN_DIR = bin

# Files and targets
TARGET = $(BIN_DIR)/cyk_algorithm.exe
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

# Default target
all: directories $(TARGET)

# Create necessary directories
directories:
	@mkdir -p $(OBJ_DIR) $(BIN_DIR)

# Linking the final executable
$(TARGET): $(OBJ_FILES)
	$(CC) $(LDFLAGS) -o $@ $^
	@echo "Build successful! Run with: ./$(TARGET)"

# Compiling source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean build artifacts
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Run the program
run: all
	$(TARGET)

# Phony targets
.PHONY: all clean run directories
