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

    def displayHelp(self):
        """
        This function displays the usage of the program.
        """
        print("USAGE: ./zappy_ai -p port -n name -h machine")
        print("\tport\tis the port number")
        print("\tname\tis the name of the team")
        print("\tmachine\tis the name of the machine; localhost by default")

    def checkParameters(self):
        """
        This function checks if the parameters are correct and if not, displays the help message.
        """
        if len(sys.argv) != 7:
            self.displayHelp()
            return 84

        for arg in sys.argv:
            if arg == "-p":
                self.port = sys.argv[sys.argv.index(arg) + 1]
            if arg == "-h":
                self.host = str(sys.argv[sys.argv.index(arg) + 1])
            if arg == "-n":
                self.name = str(sys.argv[sys.argv.index(arg) + 1])

        if len(self.port) == 0 or len(self.host) == 0 or len(self.name) == 0:
            self.displayHelp()
            return 84