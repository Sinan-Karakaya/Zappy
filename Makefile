##
## EPITECH PROJECT, 2023
## Zappy
## File description:
## Makefile
##

NPROC = $(shell nproc)

all: zappy_server zappy_ai zappy_gui

zappy_server:
	make -C zappy_server_dir/
	cp zappy_server_dir/zappy_server .

zappy_ai:
	make -C zappy_ai_dir/
	cp zappy_ai_dir/zappy_ai .
	cp -r zappy_ai_dir/src .

zappy_gui:
	mkdir -p zappy_gui_dir/build && cd zappy_gui_dir/build && cmake .. && make -j $(NPROC)
	cp zappy_gui_dir/build/zappy_gui .
	cp -r zappy_gui_dir/build/assets .

clean:
	make clean -C zappy_server_dir/
	make clean -C zappy_gui_dir/build

fclean:
	make fclean -C zappy_server_dir/
	rm -f zappy_gui
	rm -f zappy_server
	rm -f zappy_ai
	rm -rf src assets zappy_gui_dir/build

re: fclean all

.PHONY: all clean fclean re
