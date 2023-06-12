##
## EPITECH PROJECT, 2023
## zappy_ai
## File description:
## Agent
##

from src.Server.Server import Server
from src.Color.Color import (
    OKGREEN,
    ENDC,
    FAIL,
    WARNING,
    OKBLUE,
    HEADER,
    OKCYAN,
    BOLD,
    UNDERLINE,
    OKBLUE,
)


class Agent:
    def __init__(self, server: Server):
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
        self.server = server
        self.vision = []
        self.isDead = False
        self.level = 0
        self.moveStack = []
        self.broadcastStack = []
        self.__levelRequirements = [
            {"player": 1, "linemate": 1},
            {"player": 2, "linemate": 1, "deraumere": 1, "sibur": 1},
            {"player": 2, "linemate": 2, "sibur": 1, "phiras": 2},
            {"player": 4, "linemate": 1, "deraumere": 1, "sibur": 2, "phiras": 1},
            {"player": 4, "linemate": 1, "deraumere": 2, "sibur": 1, "mendiane": 3},
            {"player": 6, "linemate": 1, "deraumere": 2, "sibur": 3, "phiras": 1},
            {
                "player": 6,
                "linemate": 2,
                "deraumere": 2,
                "sibur": 2,
                "mendiane": 2,
                "phiras": 2,
                "thystame": 1,
            },
        ]

    def askServer(self, msg: str):
        """
        Sends a message to the server and returns the response.

        @param msg: The message to send to the server.
        @type msg: str

        @return: The response from the server.
        """
        print("Sending: " + msg, end=" ")
        self.server.socket.sendall((msg + "\n").encode("ASCII"))
        response = self.server.getResponse()
        if response == "dead\n":
            self.isDead = True
            exit(0)
        if "Incantation" in msg:
            response = self.server.getResponse()
        while "message" in response:
            self.broadcastStack.append(response)
            print(OKBLUE, "New message: " + response, end=ENDC)
            response = self.server.getResponse()
        if "ok" in response:
            print(OKGREEN, "| Receive: " + response, end=ENDC)
        elif "ko" in response:
            print(WARNING, "| Receive: " + response, end=ENDC)
        else:
            print(OKCYAN, "| Receive: " + response, end=ENDC)
        return response

    def fillInventory(self):
        """
        Fills the inventory of the agent by sending a request to the server and parsing the response.

        @return: None
        """
        response = self.askServer("Inventory")
        response = response.replace("[", "").replace("]", "").replace("\n", "")
        response_tab = response.split(",")

        try:
            for i in range(0, len(response_tab)):
                response_tab[i] = response_tab[i].split(" ")
                self.inventory[response_tab[i][1]] = int(response_tab[i][2])
        except:
            print("Error while parsing inventory")
            print(response)

    def fillVisions(self):
        """
        Fills the visions of the agent by sending a request to the server and parsing the response.

        @return: None
        """
        response = self.askServer("Look")
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

    def searchObject(self, object: str):
        """
        Search for an object in the vision of the agent and move to it if it is found.

        @param server: The server object used to communicate with the server.
        @type server: Server

        @return: None
        """
        indexObject = -1
        minDistance = -1

        self.fillVisions()
        for tile, index in zip(self.vision, range(0, len(self.vision))):
            if object in tile:
                distance = self.distanceTo(index)
                if minDistance == -1 or distance < minDistance:
                    indexObject = index
                    minDistance = distance

        if indexObject == 0:
            self.askServer("Take " + object)
        elif indexObject != -1:
            self.fillMoveStack(indexObject)
            while len(self.moveStack) > 0:
                print(self.askServer(self.moveStack.pop()))
            self.askServer("Take " + object)
        else:
            self.askServer("Forward")

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

    def __verifyVision(self, needed: dict):
        """
        Verify if the vision of the agent contains the needed resources.

        @param needed: The resources needed.
        @type needed: dict

        @return: bool
        """
        self.fillVisions()
        for key in needed:
            if key not in self.vision[0]:
                return False
            if self.vision[0].count(key) < needed[key]:
                return False
        return True

    def canElevate(self):
        """
        Return true if its possible to Level Up.

        @return: bool
        """
        if self.__verifyVision(self.__levelRequirements[self.level - 1]):
            return True
        return False

    def __prepareTile(self, rock_needed: dict):
        """
        Prepare the tile to level up. Clear the tile of all the rocks that are not needed.


        @param rock_needed: The rocks needed to level up.
        @type rock_needed: dict

        @return: None
        """
        for key in rock_needed:
            for i in range(
                0, self.__levelRequirements[self.level][key] - self.vision[0].count(key)
            ):
                if key != "player":
                    self.askServer("Set " + key)
        for rock in self.vision[0]:
            if (rock != "player" and rock != "food") and (
                (rock not in self.__levelRequirements[self.level])
                or (
                    self.vision[0].count(rock)
                    > self.__levelRequirements[self.level][rock]
                )
            ):
                self.askServer("Take " + rock)

    def __gatherRocks(self):
        """
        Gather all the rocks needed to level up.

        @param server: The server object used to communicate with the server.
        @type server: Server

        @return: (dict, bool)
        @rtype: (dict, bool)
        @return: The rocks needed to level up and if the agent has all the rocks needed.
        """
        rock_needed = dict(self.__levelRequirements[self.level])

        for key in rock_needed:
            if key != "player":
                rock_needed[key] -= self.inventory[key]

        for key in rock_needed:
            if rock_needed[key] > 0 and key != "player":
                self.searchObject(key)

        hasAllRock = True
        for key in rock_needed:
            if rock_needed[key] != 0 and key != "player":
                hasAllRock = False
                break
        return (rock_needed, hasAllRock)

    def joinIncantate(self):
        lenBroadcast = len(self.broadcastStack)
        if len(self.broadcastStack) > 0 and "incanting" in self.broadcastStack[-1]:
            self.broadcast("I'm joining the incantation")
            direction = int(self.broadcastStack[-1][8])
            if direction == 3:
                self.askServer("Left")
            elif direction == 7:
                self.askServer("Right")
            else:
                self.askServer("Forward")
        else:
            self.broadcast("I'm incanting " + str(self.level) + "!")

                
                
    def elevate(self):
        """
        Elevate the agent to the next level. gathering all rock and player


        @return: None
        """
        rock_needed, hasAllRock = self.__gatherRocks()
        self.fillVisions()
        if hasAllRock:
            while (
                self.vision[0].count("player")
                < self.__levelRequirements[self.level]["player"]
            ):
                self.joinIncantate()
                self.fillVisions()
                self.fillInventory()
                if self.inventory["food"] < 7:
                    self.searchObject("food")

            self.__prepareTile(rock_needed)
            response = self.askServer("Incantation")
            if not "ko" in response:
                self.level += 1

    def broadcast(self, message: str):
        ...

    def live(self):
        ...

    def birth(self):
        ...

    def run(self):
        """
        Run the agent.

        @return: None"""
        self.birth()
        while not self.isDead:
            self.live()
