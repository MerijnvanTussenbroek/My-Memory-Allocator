# ================================
#  Simple C Project Makefile
# ================================

# Compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra -g
LDFLAGS := -lm

# Project structure
SRC_DIR := src
INC_DIR := include
OBJ_DIR := obj

# Automatically include all subdirectories in include/
INC_DIRS := $(shell find $(INC_DIR) -type d)
CFLAGS += $(addprefix -I, $(INC_DIRS))

# Executable name (placed in project root)
TARGET := program

# Gather sources and objects
SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Default target
all: $(TARGET)

# Link object files into executable
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

# Compile each .c to .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create obj directory if needed
$(OBJ_DIR):
	mkdir -p $@

# Clean up build files
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Phony targets
.PHONY: all clean

