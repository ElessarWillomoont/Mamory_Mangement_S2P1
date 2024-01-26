CC=gcc
CFLAGS=-shared -fPIC
TARGET=lib_my_malloc.so
SOURCE=heap_lib.c

all:
    $(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

clean:
    rm -f $(TARGET)