##
## EPITECH PROJECT, 2023
## Zappy
## File description:
## Makefile
##

NPROC := $(shell nproc)

all: zappy_server zappy_gui zappy_ai

zappy_server:
	make -C zappy_server_dir/
	cp zappy_server_dir/zappy_server .

zappy_gui:
	mkdir zappy_gui_dir/build && cd zappy_gui_dir/build && cmake .. && make -j $(NPROC)
	cp zappy_gui_dir/build/zappy_gui .
	cp -r zappy_gui_dir/build/assets .

zappy_ai:
	make -C zappy_ai_dir/
	cp zappy_ai_dir/zappy_ai .
	cp -r zappy_ai_dir/src .

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
