# 学生成绩管理系统 - MinGW Makefile
# 编译：mingw32-make
# 运行：mingw32-make run
# 清理：mingw32-make clean

CC      = gcc
CFLAGS  = -std=c11 -Wall -Wextra -g -finput-charset=UTF-8 -fexec-charset=UTF-8
TARGET  = students_g.exe
SRC     = students_g.c
OBJ     = $(SRC:.c=.o)

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	@chcp 65001 >nul && $(TARGET)

clean:
	@if exist $(OBJ) del /Q $(OBJ)
	@if exist $(TARGET) del /Q $(TARGET)
