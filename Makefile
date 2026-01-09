# Compiler settings
CC = gcc
CFLAGS = -fPIC -Wall -I./inc
LDFLAGS = -shared

# Target output files
TARGET = libsai.so.1.0.0
SONAME = libsai.so.1

# Source files (Added sai_vlan.c here)
SRC = src/sai.c src/sai_vlan.c
OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	# Link the object files into a shared library
	$(CC) $(LDFLAGS) -Wl,-soname,$(SONAME) -o $@ $^

%.o: %.c
	# Compile C files to Object files
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(TARGET)