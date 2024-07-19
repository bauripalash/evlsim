CC:=cc
OUT_DIR:=dist
TARGET:=$(OUT_DIR)/elsim
SRC_DIR:=src
INCLUDE_DIR:=$(SRC_DIR)/include
RAYLIB_H:=$(INCLUDE_DIR)/raylib.h
SRCS:=$(SRC_DIR)/evlbit.c $(SRC_DIR)/common.c $(SRC_DIR)/main.c

all: run

run: build
	./$(TARGET)

build: mdir
	$(CC) -o $(TARGET) $(SRCS) $(RAYLIB_H) -lm -lraylib

mdir:
	mkdir -p $(OUT_DIR)


