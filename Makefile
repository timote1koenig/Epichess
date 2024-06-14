##
## EPITECH PROJECT, 2023
## Epichess
## File description:
## makefile
##

SRC = $(shell find src/ -type f -name "*.c")

OBJ = $(SRC:src/%.c=obj/%.o)

NAME = Epichess

CFLAGS = -Wall -Wextra -I./SFML/Graphics -I./SFML/Window	\
	-I./SFML/Config -I./SFML/Audio -I./SFML/System -I./include -g

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) -lcsfml-graphics -lcsfml-window	\
        -lcsfml-audio -lcsfml-system -lm

obj/%.o: src/%.c
	mkdir -p $(dir $@)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -rf obj

fclean: clean
	rm -f $(NAME)

running:
	./$(NAME)

run: all running fclean

re: clean fclean all
