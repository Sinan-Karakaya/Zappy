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
                currentMessage = self.broadcastStack[
                    randint(0, len(self.broadcastStack) - 1)
                ]
                currentMessage = currentMessage.split(",")[1]
                if not self.teamName in currentMessage:
                    message = self.broadcastStack[i]
                    break
            if message is None:
                return

            message = message.split(",")[1]
            self.askServer(server, "Broadcast " + message)

    def live(self, server: Server):
        """
        The main function of the agent. It is called every turn.

        @param server: The server object used to communicate with the server.
        @type server: Server

        @return: None
        """
        if len(self.broadcastStack) > 0 and "incanting" in self.broadcastStack[-1]:
            print("OKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK")
        if self.inventory["food"] <= 10:
            self.state = "Searching food"
        else:
            self.state = "Broadcasting like a fool"

        if self.state == "Searching food":
            self.searchObject(server, "food")

        if self.state == "Broadcasting like a fool":
            self.repeat(server)
            self.state = "Searching rock"

        if self.state == "Searching rock":
            self.elevate(server)
            self.state = "Searching food"

        # self.searchObject(server, "food")
        self.fillInventory(server)
        # print(self.inventory)

    def birth(self, server: Server):
        """
        Call when the agent is born.

        @param server: The server object used to communicate with the server.
        @type server: Server

        @return: None
        """

        self.broadcast(server, "I'm born")
        self.state = "Searching food"

    def broadcast(self, server: Server, message: str):
        """
        Call when the agent need to comunicat so it can use is language.

        @param server: The server object used to communicate with the server.
        @type server: Server

        @param message: The message to send.
        @type message: str

        @return: None
        """
        self.askServer(server, "Broadcast " + self.teamName + " " + message),