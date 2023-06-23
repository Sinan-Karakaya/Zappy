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
from src.Basic.Basic import Basic
from src.Graphics.Graphics import Graphics
from random import randint


def main():
    args = Parameters()

    if args.checkParameters() == 84:
        exit(84)

    server = Server(args.host, int(args.port))
    server.connect()

    if args.random:
        id = randint(0, 2)
        if id == 0:
            myAgent = Basic(args.name, server)
        else:
            myAgent = Repetoile(args.name, server)
    else:
        myAgent = Repetoile(args.name, server)

    server.printResponse()
    server.socket.sendall((args.name + "\n").encode("ASCII"))
    server.printResponse()

    if args.graphical:
        myWindow = Graphics(myAgent)
        myWindow.runGraphics()
    else:
        myAgent.run()

    server.socket.close()


if __name__ == "__main__":
    main()
