#!/usr/bin/env python3
##
## EPITECH PROJECT, 2023
## Zappy
## File description:
## main
##

##
## EPITECH PROJECT, 2023
## zappy_ai
## File description:
## main
##

from src.Parameters.Parameters import Parameters
from src.Server.Server import Server
from src.Agent.Agent import Agent
from src.Repetoile.Repetoile import Repetoile


def main():
    args = Parameters()
    args.checkParameters()
    myAgent = Repetoile(args.name)

    server = Server(args.host, int(args.port))
    server.connect()

    server.printResponse()
    server.socket.sendall((args.name + "\n").encode("ASCII"))
    server.printResponse()

    myAgent.run(server)

    server.socket.close()


if __name__ == "__main__":
    main()
