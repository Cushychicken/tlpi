TARGET = liberror_functions.so libget_num.so
CC = gcc
CFLAGS = -Wall -Werror
HEADERS = error_functions.h get_num.h
SRCS = error_functions.c get_num.c

OBJS = $(SRCS:.c=.o)

.PHONY: default all clean

default: $(TARGET)
all: default

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -shared $< -o $@

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c -fpic $< -o $@

clean:
	$(RM) *.o *.so 
