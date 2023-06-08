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
    def __init__(self, teamName, server):
        super().__init__(server)
        self.teamName = teamName
        print("Team name: " + self.teamName)
        self.state = "Searching food"

    def repeat(self):
        """
        Repeat a message from the broadcast stack if the message is not from the same team.

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
            self.askServer("Broadcast " + message)

    def live(self):
        """
        The main function of the agent. It is called every turn.

        @return: None
        """
        if self.inventory["food"] <= 10:
            self.state = "Searching food"
        else:
            self.state = "Broadcasting like a fool"

        if self.state == "Searching food":
            self.searchObject("food")

        if self.state == "Broadcasting like a fool":
            self.repeat()
            self.state = "Searching rock"

        if self.state == "Searching rock":
            self.elevate()

        # self.searchObject("food")
        self.fillInventory()
        # print(self.inventory)

    def birth(self):
        """
        Call when the agent is born.

        @return: None
        """

        self.broadcast("I'm born")
        self.state = "Searching food"

    def broadcast(self, message: str):
        """
        Call when the agent need to comunicat so it can use is language.

        @param server: The server object used to communicate with the server.
        @type server: Server

        @param message: The message to send.
        @type message: str

        @return: None
        """
        self.askServer("Broadcast " + self.teamName + " " + message),
