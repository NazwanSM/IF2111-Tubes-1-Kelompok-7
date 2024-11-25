# Compiler yang digunakan
CC = gcc

# Nama executable/program akhir
TARGET = program

# Direktori source files (satu level ke atas karena Makefile ada di bin)
SRC_DIR = ../src
ADT_DIR = $(SRC_DIR)/ADT
MAIN = ../main.c

# Daftar semua source files
SOURCES = $(MAIN) \
	$(CONSOLE) \
        $(ADT_DIR)/addon.c \
        $(ADT_DIR)/arraydin.c \
        $(ADT_DIR)/list.c \
        $(ADT_DIR)/readTxt.c \
        $(ADT_DIR)/mesinkata.c \
        $(ADT_DIR)/mesinkarakter.c \
        $(ADT_DIR)/queue.c \
        $(SRC_DIR)/start.c \
        $(SRC_DIR)/work.c \
        $(SRC_DIR)/work_challenge.c \
        $(SRC_DIR)/load.c \
        $(SRC_DIR)/save.c \
        $(SRC_DIR)/help.c \
        $(SRC_DIR)/quit.c \
        $(SRC_DIR)/register.c \
        $(SRC_DIR)/login.c \
        $(SRC_DIR)/logout.c \
        $(SRC_DIR)/storeList.c \
        $(SRC_DIR)/storeRequest.c \
        $(SRC_DIR)/storeSupply.c \
        $(SRC_DIR)/storeRemove.c

# Object files (akan dibuat di folder bin)
OBJECTS = $(SOURCES:%.c=%.o)

# Default target
all: $(TARGET)

# Linking
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

# Kompilasi source files menjadi object files
%.o: %.c
	$(CC) -c $< -o $@

# Membersihkan file hasil kompilasi
clean:
	rm -f $(OBJECTS) $(TARGET)

# Target untuk mengkompilasi ulang semuanya
rebuild: clean all

.PHONY: all clean rebuild
