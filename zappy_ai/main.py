#!/usr/bin/env python3
##
## EPITECH PROJECT, 2023
## Zappy
## File description:
## main
##

from src.Parameters.Parameters import Parameters
from src.Server.Server import Server
from src.Repetoile.Repetoile import Repetoile


def main():
    args = Parameters()

    if args.checkParameters() == 84:
        exit(84)

    server = Server(args.host, int(args.port))
    server.connect()

    myAgent = Repetoile(args.name, server)

    server.printResponse()
    server.socket.sendall((args.name + "\n").encode("ASCII"))
    server.printResponse()

    myAgent.run()

    server.socket.close()


if __name__ == "__main__":
    main()
