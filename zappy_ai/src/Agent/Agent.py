##
## EPITECH PROJECT, 2023
## zappy_ai
## File description:
## Agent
##

from src.Server.Server import Server


class Agent:
    def __init__(self):
        self.actions = {}
        self.inventory = {
            "food": 0,
            "linemate": 0,
            "deraumere": 0,
            "sibur": 0,
            "mendiane": 0,
            "phiras": 0,
            "thystame": 0,
        }
        self.vision = []
        self.isDead = False
        self.level = 1
        self.moveStack = []
        self.broadcastStack = []
        self.__levelRequirements = [{"player": 1, "linemate": 1},
                                  {"player": 2, "linemate": 1, "deraumere": 1, "sibur": 1},
                                  {"player": 2, "linemate": 2, "sibur": 1, "phiras": 2},
                                  {"player": 4, "linemate": 1, "deraumere": 1, "sibur": 2, "phiras": 1},
                                  {"player": 4, "linemate": 1, "deraumere": 2, "sibur": 1, "mendiane": 3},
                                  {"player": 6, "linemate": 1, "deraumere": 2, "sibur": 3, "phiras": 1},
                                  {"player": 6, "linemate": 2, "deraumere": 2, "sibur": 2, "mendiane": 2, "phiras": 2, "thystame": 1}]

    def askServer(self, server: Server, msg: str):
        """
        Sends a message to the server and returns the response.

        @param server: The server object used to communicate with the server.
        @type server: Server

        @param msg: The message to send to the server.
        @type msg: str

        @return: The response from the server.
        """
        print("Sending: " + msg, end=" ")
        server.socket.sendall((msg + "\n").encode("ASCII"))
        response = server.getResponse()
        if response == "dead\n":
            self.isDead = True
        if "message" in response:
            self.broadcastStack.append(response)
            response = server.getResponse()
        if "Elevation underway" in response:
            response = server.getResponse()
        print("| Receive: " + response, end="")
        return response

    def fillInventory(self, server: Server):
        """
        Fills the inventory of the agent by sending a request to the server and parsing the response.

        @param server: The server object used to communicate with the server.
        @type server: Server

        @return: None
        """
        response = self.askServer(server, "Inventory")
        response = response.replace("[", "").replace("]", "").replace("\n", "")
        response_tab = response.split(",")

        try:
            for i in range(0, len(response_tab)):
                response_tab[i] = response_tab[i].split(" ")
                self.inventory[response_tab[i][1]] = int(response_tab[i][2])
        except:
            print("Error while parsing inventory")
            print(response)

    def fillVisions(self, server: Server):
        """
        Fills the visions of the agent by sending a request to the server and parsing the response.

        @param server: The server object used to communicate with the server.
        @type server: Server

        @return: None
        """
        response = self.askServer(server, "Look")
        response = response.replace("[", "").replace("]", "").replace("\n", "")
        response_tab = response.split(",")

        currentVision = []
        for i in range(0, len(response_tab)):
            response_tab[i] = response_tab[i].split(" ")
            currentVision.append(response_tab[i][1:])
        self.vision = currentVision

    def __getYtoGo(self, listIndex: int):
        """
        return the number of time to forward to be on the same row as listIndex

        @param listIndex: The index of the vision list to go to.
        @type listIndex: int

        @return: int
        """
        yToReturn = 0
        currentIndex = listIndex
        currentOdd = 3
        while currentIndex > 0:
            currentIndex -= currentOdd
            currentOdd += 2
            yToReturn += 1
        return yToReturn

    def __getXandDirectionToGo(self, listIndex: int):
        """
        return the number of time to forward to be on the same column as listIndex

        @param listIndex: The index of the vision list to go to.
        @type listIndex: int

        @param yToGo: The number of time to forward to be on the same row as listIndex
        @type yToGo: int

        @return: (int, string)
        """
        caseCenter = 0
        currentOdd = 0
        y = self.__getYtoGo(listIndex)
        for i in range(0, y):
            currentOdd += 2
            caseCenter += currentOdd

        if listIndex == caseCenter:
            return (0, None)

        direction = None
        xToGo = caseCenter - listIndex
        if xToGo < 0:
            xToGo = -xToGo
            direction = "Right"
            return (xToGo, direction)

        xToGo = xToGo
        direction = "Left"
        return (xToGo, direction)

    def fillMoveStack(self, listIndex: int):
        """
        Fill the moveStack of the agent to go to the index of the vision list.

        @param listIndex: The index of the vision list to go to.
        @type listIndex: int

        @return: None
        """

        if listIndex <= 0:
            return
        yToGo = self.__getYtoGo(listIndex)
        xToGo, direction = self.__getXandDirectionToGo(listIndex)
        for i in range(0, yToGo):
            self.moveStack.append("Forward")
        if direction != None:
            self.moveStack.append(direction)
        for i in range(0, xToGo):
            self.moveStack.append("Forward")

    def distanceTo(self, listIndex: int):
        """
        Returns the distance to the index of the vision list.

        @param listIndex: The index of the vision list to go to.
        @type listIndex: int

        @return: int
        """
        yToGo = self.__getYtoGo(listIndex)
        xToGo, direction = self.__getXandDirectionToGo(listIndex)
        return yToGo + xToGo

    def __verifyVision(self, server: Server, needed: dict):
        """
        Verify if the vision of the agent contains the needed resources.

        @param server: The server object used to communicate with the server.
        @type server: Server

        @param needed: The resources needed.
        @type needed: dict

        @return: bool
        """
        for key in needed:
            if key not in self.vision[0]:
                return False
            if self.vision[0].count(key) < needed[key]:
                return False
        return True

    def canElevate(self, server: Server):
        """
        Return true if its possible to Level Up.

        @param server: The server object used to communicate with the server.
        @type server: Server

        @return: bool
        """

        if self.__verifyVision(server, self.__levelRequirements[self.level]):
            return True
        return False

    def live(self, server: Server):
        ...

    def birth(self, server: Server):
        ...

    def run(self, server: Server):
        self.birth(server)
        while not self.isDead:
            self.live(server)
