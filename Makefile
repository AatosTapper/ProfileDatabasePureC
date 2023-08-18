# Compiler and compiler flags
CC := gcc
CFLAGS := -Wall -Wextra -g
CVERSION := -std=c17

# Directories
SRC_DIR := src
BUILD_DIR := build
BIN_DIR := bin

# Source files (assuming all .c files are in the src directory)
SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))

# Target executable
TARGET := $(BIN_DIR)/myapp

run: $(TARGET)
	$(TARGET)

# Phony targets (targets that are not real files)
.PHONY: all clean

# Default target
all: $(TARGET)

# Compile the object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Link the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Clean the build
clean:
	rm -rf $(BUILD_DIR)/* $(BIN_DIR)/*

# del /s /q $(BUILD_DIR) $(BIN_DIR) <- Windows
# rm -rf $(BUILD_DIR)/* $(BIN_DIR)/* <- MacOS

