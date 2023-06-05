#!/usr/bin/env python3

from src.Parameters.Parameters import Parameters
from src.Server.Server import Server
from src.Agent.Agent import Agent
from src.Repetoile.Repetoile import Repetoile


def main():
    myAgent = Repetoile()
    args = Parameters()

    server = Server(args.host, int(args.port))
    server.connect()

    server.printResponse()
    server.socket.sendall((args.name + "\n").encode("ASCII"))
    server.printResponse()

    myAgent.fillInventory(server)

    # print(myAgent.getYtoGo(server, 15))
    print(myAgent.getXandDirectionToGo(13))
    # myAgent.run(server)
    print("dead")

    server.socket.close()


if __name__ == "__main__":
    main()
