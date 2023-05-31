#!/usr/bin/env python3

from src.Parameters.Parameters import Parameters
from src.Server.Server import Server
from src.Agent.Agent import Agent


def main():
    myAgent = Agent()
    args = Parameters()

    server = Server(args.host, int(args.port))
    server.connect()

    server.printResponse()
    server.socket.sendall((args.name + "\n").encode("ASCII"))
    server.printResponse()

    myAgent.fillInventory(server)

    # while True:
    #     server.printResponse()
    #     if server.data == "dead\n":
    #         break
    #     msg = input() + "\n"
    #     server.socket.sendall(msg.encode("ASCII"))

    server.socket.close()


if __name__ == "__main__":
    main()
