##
## EPITECH PROJECT, 2023
## zappy_ai
## File description:
## Basic
##

from src.Agent.Agent import Agent
from src.Server.Server import Server
from random import randint
from src.Color.Color import WARNING


class Basic(Agent):
    def __init__(self, teamName, server):
        super().__init__(server)
        self.teamName = teamName
        self.state = "Searching food"

    def live(self):
        """
        The main function of the agent. It is called every turn.

        @return: None
        """
        if self.inventory["food"] <= 40 and self.state != "Joining":
            self.state = "Searching food"
        elif self.state == "Joining" and self.inventory["food"] < 20:
            self.state = "Searching food"
        else:
            self.state = "Searching rock"

        if self.state == "Searching rock":
            hasAllRock = self.elevate()
            if hasAllRock:
                self.state = "Joining"

        if self.state == "Searching food":
            self.searchObject("food")

        self.fillInventory()

    def birth(self):
        """
        Call when the agent is born.

        @return: None
        """

        self.broadcast("I'm born as a basic agent !")
        self.state = "Searching food"

    def checkMessageId(self, id: int):
        for message in self.broadcastStack:
            try:
                if id == message.split(":")[1]:
                    return True
                elif id in self.idStack:
                    return True
            except:
                ...
        return False

    def canUseMessage(self, message: str):
        return True

    def broadcast(self, message: str):
        """
        Call when the agent need to communicate so it can use is language.

        @param server: The server object used to communicate with the server.
        @type server: Server

        @param message: The message to send.
        @type message: str

        @return: None
        """
        self.askServer("Broadcast " + message)
