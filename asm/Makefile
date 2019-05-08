CPPFLAGS = -I./include
CFLAGS = -m64 -Wall -Wextra
LDLIB =

%.o: %.c
	gcc $(CFLAGS) $(CPPFLAGS) -c $< -o $@

SRC = $(wildcard ./src/*.c) $(wildcard ./src/*/*.c) $(wildcard ./src/*/*/*.c)
OBJ = $(SRC:.c=.o)

OUTPUT = asm

debug: CFLAGS += -g
debug: all

release: CFLAGS += -O3
release: all

all: $(OUTPUT)

$(OUTPUT): $(OBJ)
	gcc $(OBJ) -o $(OUTPUT)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(OUTPUT)

re: fclean all

.PHONY: all clean fclean re debug release
