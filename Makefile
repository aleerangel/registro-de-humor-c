#Windows com gcc

CC = gcc
CFLAGS = -Wall -Wextra -std=c11

SOURCES = main.c ListaDuplamenteEnc.c RegistroDeHumor.c
OBJ = $(SOURCES:.c=.o)
EXEC = registroHumor.exe

all: $(EXEC)
	@./$(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del $(OBJ) $(EXEC) 2>nul || rm -f $(OBJ) $(EXEC)