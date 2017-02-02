TARGET = copy

CC = gcc
CFLAGS = -Wall -Werror
LIBPATH = -L../../lib/
SHARLIB = -lerror_functions -lget_num
INCLUDE = -I../../lib/

all: $(TARGET)

OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))
HEADERS = $(wildcard *.h)

%.o: %.c $(HEADERS) 
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ 

$(TARGET): $(OBJECTS)
	@$(CC) $(CFLAGS) $(LIBPATH) $(INCLUDE) $(OBJECTS) $(LIBS) -o $@ $(SHARLIB) 

clean:
	@rm -f *.o
	@rm -f $(TARGET)
	
