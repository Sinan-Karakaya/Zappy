##
## EPITECH PROJECT, 2023
## zappy_ai
## File description:
## main
##

import sys
from src.Server.Server import Server

server = Server(str(sys.argv[3]), int(sys.argv[1]))
server.connect()

data = server.socket.recv(1024)
print(data.decode("ASCII"), end="")
server.socket.sendall((sys.argv[2] + "\n").encode("ASCII"))
data = server.socket.recv(1024)
print(data.decode("ASCII"), end="")

while (data != "dead\n"):
    msg = input() + "\n"
    server.socket.sendall(msg.encode("ASCII"))
    data = server.socket.recv(1024)
    print(data.decode("ASCII"), end="")
