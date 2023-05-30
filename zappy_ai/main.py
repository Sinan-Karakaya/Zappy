##
## EPITECH PROJECT, 2023
## zappy_ai
## File description:
## main
##

import sys
from src.Server.Server import Server

def checkParameters():
    if (sys.argv[1] == "-help"):
        print("USAGE: ./zappy_ai -p port -n name -h machine")
        print("\tport\tis the port number")
        print("\tname\tis the name of the team")
        print("\tmachine\tis the name of the machine; localhost by default")
        exit(0)

    if (len(sys.argv) < 7):
        exit(84)

    for arg in sys.argv:
        if (arg == "-p"):
            port = sys.argv[sys.argv.index(arg) + 1]
        if (arg == "-h"):
            host = str(sys.argv[sys.argv.index(arg) + 1])
        if (arg == "-n"):
            name = str(sys.argv[sys.argv.index(arg) + 1])

    if (len(port) == 0 or len(host) == 0 or len(name) == 0):
        exit(84)
    
    return (port, host, name)

def main():
    args = checkParameters()

    server = Server(args[1], int(args[0]))
    server.connect()

    server.printResponse()
    server.socket.sendall((args[2] + "\n").encode("ASCII"))

    while (True):
        server.printResponse()
        msg = input() + "\n"
        if (msg == "exit\n"):
            break
        server.socket.sendall(msg.encode("ASCII"))

    server.socket.close()

main()