##
## EPITECH PROJECT, 2023
## zappy_ai
## File description:
## Parameters
##

import sys


class Parameters:
    def __init__(self):
        self.port = ""
        self.host = "localhost"
        self.name = ""
        self.graphical = False

    def displayHelp(self):
        """
        This function displays the usage of the program.

        @return: None
        """
        print("USAGE: ./zappy_ai -p port -n name -h machine")
        print("\tport\tis the port number")
        print("\tname\tis the name of the team")
        print("\tmachine\tis the name of the machine; localhost by default")
        print("\t[-g]\t to enable graphical mode")

    def checkParameters(self):
        """
        This function checks if the parameters are correct and if not, displays the help message.

        @return: 84 if the parameters are incorrect, 0 otherwise
        """
        if len(sys.argv) < 7 or len(sys.argv) > 8:
            self.displayHelp()
            return 84

        for arg in sys.argv:
            if arg == "-p":
                self.port = sys.argv[sys.argv.index(arg) + 1]
            if arg == "-h":
                self.host = str(sys.argv[sys.argv.index(arg) + 1])
            if arg == "-n":
                self.name = str(sys.argv[sys.argv.index(arg) + 1])
            if arg == "-g":
                self.graphical = True

        if len(self.port) == 0 or len(self.host) == 0 or len(self.name) == 0:
            self.displayHelp()
            return 84
