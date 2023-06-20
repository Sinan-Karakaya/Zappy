##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile for zappy_server
##

NAME	=	zappy_server

SRC_DIR = 	src/

SRC	=	$(shell find src/ -name "*.c")

SRC_BIS	=	$(shell find src/**/ -name "*.c")
SRC_TESTS	=	$(shell find tests/ -name "*.c")

OBJ	=	$(SRC:.c=.o)

OBJ_BIS	=	$(SRC_BIS:.c=.o)

LIBFLAGS	=	-L lib/my/ -lmy -I include/

LD_FLAGS	=	-lm

CFLAGS += -Wextra -W -Wall -I include/

all: $(NAME)

$(NAME): $(OBJ)
	@gcc  -o $(NAME) $(OBJ) $(CFLAGS) $(LD_FLAGS)

clean:
	@rm -f $(OBJ)


fclean:	clean
	@rm -f $(NAME)
	@rm -f unit_tests
	@rm -f *.gcda
	@rm -f *.gcno

tests_run: $(OBJ_BIS)
	@gcc -o unit_tests $(SRC_BIS) $(SRC_TESTS) $(CFLAGS) $(LD_FLAGS) \
	--coverage -lcriterion
	./unit_tests
	make fclean

re:	fclean all

debug :	CFLAGS += -g
debug : re
