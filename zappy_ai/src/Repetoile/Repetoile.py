##
## EPITECH PROJECT, 2023
## zappy_ai
## File description:
## Repetoile
##

from src.Agent.Agent import Agent
from src.Server.Server import Server
from random import randint
from src.Color.Color import WARNING


class Repetoile(Agent):
    def __init__(self, teamName, server):
        super().__init__(server)
        self.teamName = teamName
        self.idStack = []
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
                    message = currentMessage
                    break
            if message is None:
                return

            try:
                self.askServer("Broadcast " + message)
            except:
                ...

    def live(self):
        """
        The main function of the agent. It is called every turn.

        @return: None
        """
        if self.inventory["food"] <= 10 and self.state != "Joining":
            self.state = "Searching food"
        elif self.state == "Joining" and self.inventory["food"] < 6:
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
        self.repeat()
        print("Curretly my state is: " + self.state)

    def birth(self):
        """
        Call when the agent is born.

        @return: None
        """

        self.broadcast("I'm born")
        self.askServer("Fork")
        self.state = "Searching food"

    def checkMessageId(self, id : int):
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
        try:
            messageId = message.split(":")[1]
            if self.checkMessageId(int(messageId)):
                return False
            return True
        except:
            return False

    def broadcast(self, message: str):
        """
        Call when the agent need to communicate so it can use is language.

        @param server: The server object used to communicate with the server.
        @type server: Server

        @param message: The message to send.
        @type message: str

        @return: None
        """
        messageId = randint(0, 2147483646)
        self.idStack.append(messageId)
        self.askServer("Broadcast " + self.teamName + " " + message + ":" + str(messageId))

