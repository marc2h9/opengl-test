CC =g++
CFLAGS =-Wall -Wextra -ggdb
LIBDIRS = $(wildcard lib/*)
INCLUDES = $(addprefix -I $(LIBDIRS))

main: src/main.cpp
	$(CC) $(CFLAGS) -o bin/main src/main.cpp include/glad/glad.c -lglfw -lGL
