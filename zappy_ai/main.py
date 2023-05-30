##
## EPITECH PROJECT, 2023
## zappy_ai
## File description:
## main
##

from time import sleep
from src.Server.Server import Server

server = Server("127.0.0.1", 4249)
server.connect()

server.socket.sendall("Troll\n".encode("ASCII"))
sleep(1)
server.socket.sendall("Inventory\n".encode("ASCII"))
data = server.socket.recv(1024)
print(data.decode("ASCII"), end="")
sleep(1)

