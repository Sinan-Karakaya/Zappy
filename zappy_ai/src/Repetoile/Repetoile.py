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

    def searchFood(self, server: Server):
        """
        Search for food in the vision of the agent and move to it if it is found.

        @param server: The server object used to communicate with the server.
        @type server: Server

        @return: None
        """
        indexFood = -1

        self.fillVisions(server)
        for tile, index in zip(self.vision, range(0, len(self.vision))):
            if "food" in tile:
                indexFood = index
                break

        if indexFood == 0:
            print(self.askServer(server, "Take food"))
        elif indexFood != -1:
            self.fillMoveStack(indexFood)
            while len(self.moveStack) > 0:
                print(self.askServer(server, self.moveStack.pop()))
            print(self.askServer(server, "Take food"))
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
        if self.inventory["food"] <= 5:
            self.state = "Searching food"
        else:
            self.state = "Broadcasting like a fool"

        if self.state == "Searching food":
            self.searchFood(server)

        if self.state == "Broadcasting like a fool":
            self.repeat(server)
            self.state = "Searching rock"

        if self.state == "Searching rock":
            print("I'm searching rock")

        self.fillInventory(server)
        print("Filling inventory")

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
