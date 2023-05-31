#!/usr/bin/env python3

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
        if server.data == "dead\n":
            break
        msg = input() + "\n"
        server.socket.sendall(msg.encode("ASCII"))

    server.socket.close()


if __name__ == "__main__":
    main()
