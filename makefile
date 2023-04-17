SRC_DIR = ./src
OUT_DIR = ./build
OBJ_DIR = $(OUT_DIR)/obj
BIN_DIR = $(OUT_DIR)/bin
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(ONJ_DIR)/%.o,$(SRC_FILES))

all:
    echo $(SRC_FILES)