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
    def __init__(self):
        super().__init__()
        self.state = "Searching food"

    def searchFood(self, server: Server):
        indexBouffe = -1
        
        self.fillVisions(server)
        for case, index in zip(self.vision, range(0, len(self.vision))):
            if 'food' in case:
                indexBouffe = index
                break
        print(self.vision)
        
        if indexBouffe == 0:
            print(self.askServer(server, "Take food"))
        elif indexBouffe != -1:
            self.fillMoveStack(indexBouffe)
            print(self.moveStack)
            while len(self.moveStack) > 0:
                print(self.askServer(server, self.moveStack.pop()))
            print(self.askServer(server, "Take food"))
        else:
            print(self.askServer(server, "Forward"))
        
        self.fillInventory(server)
        print(self.inventory)

    def repeat(self, server: Server):
        if len(self.broadcastStack) > 0:
            print("Broadcasting: ", self.askServer(server, "Broadcast " + self.broadcastStack[randint(0, len(self.broadcastStack) - 1)]))
        
        self.fillInventory(server)
        print(self.inventory)


    def live(self, server: Server):
        if (self.inventory["food"] <= 5):
            self.state = "Searching food"
        else:
            self.state = "Broadcasting like a fool"
        
        if (self.state == "Searching food"):
            self.searchFood(server)
        
        if (self.state == "Broadcasting like a fool"):
            self.repeat(server)

    def birth(self, server: Server):
        print("Broadcast: ",self.askServer(server, "Broadcast I'm born !"))
        self.state = "Searching food"
        
