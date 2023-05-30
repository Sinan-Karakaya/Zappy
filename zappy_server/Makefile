##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile for zappy_server
##

NAME	=	zappy_server

SRC_DIR = 	src/

SRC	= $(shell find src/ -name "*.c")

OBJ	=	$(SRC:.c=.o)

LIBFLAGS	=	-L lib/my/ -lmy -I include/

LD_FLAGS += -luuid -lm

CFLAGS += -Wextra -W -Wall -I include/ -g

all: $(NAME)

$(NAME): $(OBJ)
	@gcc  -o $(NAME) $(OBJ) $(CFLAGS) $(LD_FLAGS)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

debug :	CFLAGS += -g
debug : re
