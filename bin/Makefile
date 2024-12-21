# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -g

# Include directories
INCLUDES = -I../src -I../src/ADT -I..

# Main source files
MAIN_SRC = ../main.c
CONSOLE_SRC = ../console.c

# Source files (exclude driver files)
SRC_FILES = \
        ../src/cartAdd.c \
        ../src/cartPay.c \
        ../src/cartRemove.c \
        ../src/cartShow.c \
        ../src/help.c \
        ../src/history.c \
        ../src/load.c \
        ../src/login.c \
        ../src/logout.c \
        ../src/profile.c \
        ../src/quit.c \
        ../src/register.c \
        ../src/save.c \
        ../src/start.c \
        ../src/storeList.c \
        ../src/storeRemove.c \
        ../src/storeRequest.c \
        ../src/storeSupply.c \
        ../src/wishlistAdd.c \
        ../src/wishlistClear.c \
        ../src/wishlistRemove.c \
        ../src/wishlistRemovei.c \
        ../src/wishlistShow.c \
        ../src/wishlistSwap.c \
        ../src/work.c \
        ../src/work_challenge.c \
        ../src/optimasiRute.c

# ADT source files (exclude driver files)
ADT_SRC_FILES = \
        ../src/ADT/addon/addon.c \
        ../src/ADT/arraydin/arraydin.c \
        ../src/ADT/list/list.c \
        ../src/ADT/listlinier/listlinier.c \
        ../src/ADT/map/map.c \
        ../src/ADT/mesinkarakter/mesinkarakter.c \
        ../src/ADT/mesinkata/mesinkata.c \
        ../src/ADT/queue/queue.c \
        ../src/ADT/readTxt/readTxt.c \
        ../src/ADT/stack/stack.c

# Target executable
TARGET = ../main.exe

# Combine all source files
ALL_SRC_FILES = $(MAIN_SRC) $(CONSOLE_SRC) $(SRC_FILES) $(ADT_SRC_FILES)

# Rule utama
all: $(TARGET)

# Kompilasi
$(TARGET): $(ALL_SRC_FILES)
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@

# Clean rule
clean:
	rm -f $(TARGET)

# Phony targets
.PHONY: all clean
