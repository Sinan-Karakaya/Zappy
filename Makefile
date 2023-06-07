##
## EPITECH PROJECT, 2023
## Zappy
## File description:
## Makefile
##

all:
	make -C zappy_server/
	make -C zappy_ai/
	mkdir zappy_gui/build && cd zappy_gui/build && cmake -G Ninja .. && ninja

clean:
	make clean -C zappy_server/
	make clean -C zappy_gui/

fclean:
	make fclean -C zappy_server/
	rm -rf zappy_gui/build
	rm -rf zappy_gui/zappy_gui
	rm zappy_ai/zappy_ai

re: fclean all

.PHONY: all clean fclean re
