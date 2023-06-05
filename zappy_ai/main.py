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


    indexBouffe = 0

    while not myAgent.isDead:

        myAgent.fillVisions(server)
        for case, index in zip(myAgent.vision, range(0, len(myAgent.vision))):
            if 'food' in case:
                indexBouffe = index
                break
        print(myAgent.vision)
        
        if indexBouffe == 0:
            print(myAgent.askServer(server, "Take food"))
        else:
            myAgent.fillMoveStack(indexBouffe)
            print(myAgent.moveStack)
            while len(myAgent.moveStack) > 0:
                print(myAgent.askServer(server, myAgent.moveStack.pop()))
            print(myAgent.askServer(server, "Take food"))
        print(myAgent.askServer(server, "Inventory"))
    
    
    print("dead")

    server.socket.close()


if __name__ == "__main__":
    main()
