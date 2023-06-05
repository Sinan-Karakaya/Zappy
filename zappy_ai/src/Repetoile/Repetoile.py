##
## EPITECH PROJECT, 2023
## zappy_ai
## File description:
## Repetoile
##

from src.Agent.Agent import Agent
from src.Server.Server import Server


class Repetoile(Agent):
    def __init__(self):
        super().__init__()

    def live(self, server: Server):
        print("live")
        self.fillVisions(server)
        print(self.vision)
