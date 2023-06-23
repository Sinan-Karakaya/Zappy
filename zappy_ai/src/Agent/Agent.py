##
## EPITECH PROJECT, 2023
## zappy_ai
## File description:
## Agent
##

import datetime
from random import randint
from src.Words.Words import words as words
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
from src.Color.Color import coloredPrint


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
        self.isElevating = False
        self.level = 0
        self.moveStack = []
        self.broadcastStack = []
        self.incatationID = randint(0, 1000000000)
        self.followID = None
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

    def __treatMessage(self, message: str):
        """
        Treats the message received from the server to avoid getting the wrong response.

        @param message: The message to treat.
        @type message: str

        @return: True if the message is valid, False otherwise.
        """
        if "dead" in message:
            self.isDead = True
            exit(0)

        if "message" in message:
            self.broadcastStack.append(message)
            return False

        if "Elevation underway" in message:
            self.isElevating = True
            self.followID = None
            return False

        return True

    def __getRealResponse(self, message: str):
        """
        Returns the real message from the server removing useless mesage like broadcast or death.

        @param message: The message to treat.
        @type message: str

        @return: The real respone.
        """
        response = message
        while not self.__treatMessage(response):
            response = self.server.getResponse()
        return response

    def __bufferManager(self, message: str):
        """
        Get the real message even if the server send it with misplace /n.

        @param message: The message to treat.
        @type message: str

        @return: The message with the real size.
        """

        while message.count("\n") < 1:
            currentResponse = self.server.getResponse()
            currentResponse = self.__getRealResponse(currentResponse)
            message += currentResponse

        return message

    def askServer(self, msg: str):
        """
        Sends a message to the server and returns the response.

        @param msg: The message to send to the server.
        @type msg: str

        @return: The response from the server.
        """

        now = datetime.datetime.now()
        print("Current time is:", now.time(), end=" ")
        print("Sending: " + msg, end=" ")
        self.server.socket.sendall((msg + "\n").encode("ASCII"))

        response = self.server.getResponse()
        response = self.__bufferManager(response)
        response = self.__getRealResponse(response)

        if "Incantation" in msg:
            if "Current level" in response:
                self.level = int(response.split(" ")[2]) - 1
                self.isElevating = False
                self.incatationID = randint(0, 1000000000)
                self.followID = None
        else:
            if "Current level" in response:
                self.level = int(response.split(" ")[2]) - 1
                self.isElevating = False
                response = self.server.getResponse()
                response = self.__getRealResponse(response)
                self.incatationID = randint(0, 1000000000)
                self.followID = None
        coloredPrint(response)

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
            print(WARNING, "Error while parsing inventory")
            print(response)
            response = self.server.getResponse()
            response = self.__getRealResponse(response)

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
        if listIndex == 0 or listIndex == 1:
            return (0, None)
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

    def gatherRocks(self):
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

    def __checkIncantationLevel(self, message: str):
        """
        check the level require to join the incantation

        @param message: The message to check
        @type message: str

        @return: bool
        """
        indexIncating = message.find(words.incanting)
        if indexIncating != -1:
            indexEnd = message.find(" ", indexIncating + len(words.incanting) + 1)
            stringLevel = message[indexIncating + len(words.incanting) + 1 : indexEnd]
            level = int(stringLevel)
            if level == self.level + 1:
                return True
        return False

    def __getFollowId(self, message: str):
        """
        get the id of the incantation

        @param message: The message to check
        @type message: str

        @return: int
        """
        indexIncating = message.find(words.incanting)
        print(message)
        if indexIncating != -1:
            indexEnd = message.find("!", indexIncating)
            stringLevel = message[indexIncating + 11 : indexEnd]
            id = int(stringLevel)
            return id
        return None

    def searchWord(self, word: str):
        for i in range(10):
            if len(self.broadcastStack) > i:
                if word in self.broadcastStack[-i]:
                    return True
        return False

    def canUseMessage(self, message: str):
        ...

    def joinIncantate(self):
        """
        Manage the meet of different agent with the same level to level up

        @return: None
        """
        if len(self.broadcastStack) > 0 and self.searchWord(words.incanting):
            if not self.__checkIncantationLevel(self.broadcastStack[-1]):
                return False

            if self.followID == None:
                self.followID = self.__getFollowId(self.broadcastStack[-1])
                return False

            if self.followID != self.__getFollowId(self.broadcastStack[-1]):
                return False
            
            if not self.canUseMessage(self.broadcastStack[-1]):
                return False

            self.broadcast("I'm joining the incantation " + str(self.followID) + "!")
            direction = int(self.broadcastStack[-1][8])
            if direction == 3:
                self.askServer("Left")
            elif direction == 7:
                self.askServer("Right")
            else:
                self.askServer("Forward")

        else:
            self.broadcast(
                "I'm "
                + words.incanting
                + " "
                + str(self.level + 1)
                + " "
                + str(self.incatationID)
                + "!"
            )

    def __getLastMessage(self):
        """
        get the last message of the broadcast stack

        @return: str
        """
        if len(self.broadcastStack) > 0:
            return self.broadcastStack[-1]
        return ""

    def elevate(self):
        """
        Elevate the agent to the next level. gathering all rock and player

        @return: None
        """
        hasJoin = False
        rock_needed, hasAllRock = self.gatherRocks()
        self.fillVisions()
        if hasAllRock:
            if (
                self.vision[0].count("player")
                < self.__levelRequirements[self.level]["player"]
            ):
                hasJoin = self.joinIncantate()
            else:
                if self.level == 0 or "joining" in self.__getLastMessage():
                    self.broadcast("I'v started incantation")
                    self.__prepareTile(rock_needed)
                    response = self.askServer("Incantation")
                else:
                    self.broadcast("I'v started incantation")
                    self.__prepareTile(rock_needed)
                    for i in range(0, 314):
                        self.askServer("Inventory")
        return hasAllRock

    def broadcast(self, message: str):
        ...

    def live(self):
        ...

    def birth(self):
        ...

    def run(self):
        """
        Run the agent.

        @return: None
        """
        self.birth()
        while not self.isDead:
            self.live()
