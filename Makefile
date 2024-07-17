CC:=cc
OUT_DIR:=dist
TARGET:=$(OUT_DIR)/elsim
SRC_DIR:=src
RAYLIB_H:=$(SRC_DIR)/raylib.h

all: run

run: build
	./$(TARGET)

build: mdir
	$(CC) -o $(TARGET) $(SRC_DIR)/main.c $(RAYLIB_H) -lm -lraylib

mdir:
	mkdir -p $(OUT_DIR)


