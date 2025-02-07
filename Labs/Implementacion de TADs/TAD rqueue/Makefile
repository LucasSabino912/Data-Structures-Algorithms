# Compilador y flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

# Archivos fuente y objetos
SRCS = main.c helpers.c rqueue.c
OBJS = $(SRCS:.c=.o)

# Nombre del ejecutable
TARGET = programa

# Regla principal: compilar el ejecutable y limpiar archivos .o
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
# Limpiar archivos .o y el ejecutable después de compilar
	rm -f $(OBJS)   

# Regla para compilar archivos .c a .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Evita que "clean" se interprete como un archivo
.PHONY: clean
