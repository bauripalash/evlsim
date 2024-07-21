CC:=gcc
CFLAGS:=-std=c11 -Wall
LDFLAGS:=-lm -lraylib -flto

OUT_DIR:=dist
BUILD_DIR:=_build
TARGET:=$(OUT_DIR)/evolsim
SRC_DIR:=src


SRCS:=evolbit.c utils.c main.c
RAYLIB_H:=$(SRC_DIR)/include/raylib.h


SRC:=$(SRCS:%=$(SRC_DIR)/%)
OBJS:=$(SRC:%=$(BUILD_DIR)/%.o)




all: run

run: $(TARGET)
	./$(TARGET)

$(TARGET): clean $(OBJS)
	@mkdir -p $(OUT_DIR)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.c.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

fmt:
	clang-format -i -style=file src/*.c src/include/*.h

clean:
	@rm -rf $(BUILD_DIR)
	@rm -rf $(OUT_DIR)
