##
## EPITECH PROJECT, 2023
## zappy_ai
## File description:
## Repetoile
##

from src.Agent.Agent import Agent
from src.Server.Server import Server
from random import randint


class Repetoile(Agent):
    def __init__(self, teamName):
        super().__init__()
        self.teamName = teamName
        self.state = "Searching food"

    def searchObject(self, server: Server, object: str):
        """
        Search for an object in the vision of the agent and move to it if it is found.

        @param server: The server object used to communicate with the server.
        @type server: Server

        @return: None
        """
        indexObject = -1
        minDistance = -1

        self.fillVisions(server)
        for tile, index in zip(self.vision, range(0, len(self.vision))):
            if object in tile:
                distance = self.distanceTo(index)
                if minDistance == -1 or distance < minDistance:
                    indexObject = index
                    minDistance = distance
                

        if indexObject == 0:
            print(self.askServer(server, "Take " + object))
        elif indexObject != -1:
            self.fillMoveStack(indexObject)
            while len(self.moveStack) > 0:
                print(self.askServer(server, self.moveStack.pop()))
            print(self.askServer(server, "Take " + object))
        else:
            print(self.askServer(server, "Forward"))

    def repeat(self, server: Server):
        """
        Repeat a message from the broadcast stack if the message is not from the same team.

        @param server: The server object used to communicate with the server.
        @type server: Server

        @return: None
        """
        if len(self.broadcastStack) > 0:
            message = None

            for i in range(randint(0, 25)):
                print("Wtf")
                currentMessage = self.broadcastStack[
                    randint(0, len(self.broadcastStack) - 1)
                ]
                currentMessage = currentMessage.split(",")[1]
                if not self.teamName in currentMessage:
                    message = self.broadcastStack[i]
                    break
            print("I'm searching rock")
            if message is None:
                return

            message = message.split(",")[1]
            print("Broadcasting: ", message)
            print("return: ", self.askServer(server, "Broadcast " + message))

    def live(self, server: Server):
        """
        The main function of the agent. It is called every turn.

        @param server: The server object used to communicate with the server.
        @type server: Server

        @return: None
        """
        # if self.inventory["food"] <= 10:
        #     self.state = "Searching food"
        # else:
        #     self.state = "Broadcasting like a fool"

        # if self.state == "Searching food":
        #     self.searchObject(server, "food")

        # if self.state == "Broadcasting like a fool":
        #     self.repeat(server)
        #     self.state = "Searching rock"

        # if self.state == "Searching rock":
        #     self.searchObject(server, "linemate")
        #     if (self.inventory["linemate"] > 0):
        #         self.askServer(server, "Set linemate")
        #         self.fillVisions(server)
        #         print(self.vision)
        #         self.askServer(server, "Incantation")

        self.searchObject(server, "food")
        self.fillInventory(server)
        print(self.inventory)


    def birth(self, server: Server):
        """
        Call when the agent is born.

        @param server: The server object used to communicate with the server.
        @type server: Server

        @return: None
        """
        print(
            "Broadcast: ",
            self.askServer(server, "Broadcast " + self.teamName + " I'm born !"),
        )
        self.state = "Searching food"

