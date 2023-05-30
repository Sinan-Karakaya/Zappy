##
## EPITECH PROJECT, 2023
## zappy_ai
## File description:
## main
##

from src.Parameters.Parameters import Parameters
from src.Server.Server import Server


def main():
    args = Parameters()

    server = Server(args.host, int(args.port))
    server.connect()

    server.printResponse()
    server.socket.sendall((args.name + "\n").encode("ASCII"))

    while True:
        server.printResponse()
        msg = input() + "\n"
        if msg == "exit\n":
            break
        server.socket.sendall(msg.encode("ASCII"))

    server.socket.close()



main()
