##
## EPITECH PROJECT, 2023
## zappy_ai
## File description:
## Agent
##

from src.Server.Server import Server

class Agent():
    def __init__(self):
        self.actions = {}
        self.inventory = {"food": 0, "linemate": 0, "deraumere": 0, "sibur": 0,"mendiane": 0, "phiras": 0, "thystame": 0}
        self.isDead = False

    def askServer(self, server : Server, msg : str):
        """
        Sends a message to the server and returns the response.

        @param server: The server object used to communicate with the server.
        @type server: Server

        @param msg: The message to send to the server.
        @type msg: str

        @return: The response from the server.
        """
        server.socket.sendall((msg + "\n").encode("ASCII"))
        response = server.getResponse()
        if response == "dead\n":
            self.isDead = True
        return response

    def fillInventory(self, server : Server):
        """
        Fills the inventory of the agent by sending a request to the server and parsing the response.

        @param server: The server object used to communicate with the server.
        @type server: Server

        @return: None
        """
        response = self.askServer(server, "Inventory")
        response = response.replace("[", "").replace("]", "").replace("\n", "")
        response_tab = response.split(",")

        for i in range(0, len(response_tab)):
            response_tab[i] = response_tab[i].split(" ")
            self.inventory[response_tab[i][1]] = int(response_tab[i][2])
    
    def chooseAction(self):
        ...

    def live(self):
        ...

    def run(self):
        while not self.isDead:
            self.live()
