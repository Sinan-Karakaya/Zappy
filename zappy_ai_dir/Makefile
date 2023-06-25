##
## EPITECH PROJECT, 2023
## zappy_ai
## File description:
## Makefile
##

all:
	cp main.py zappy_ai
	chmod +x zappy_ai

clean:
	rm -f zappy_ai

fclean: clean

testrun:
	coverage run -m unittest discover -s tests/ -p "test_*.py"
	python3 -m coverage html

re: fclean all

.PHONY: all
