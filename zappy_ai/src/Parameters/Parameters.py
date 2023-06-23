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
        self.random = False

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
        print("\t[-r]\t to enable random selection of ai")

    def nbOfParametersRequired(self):
        """
        This function returns the number of parameters required.

        @return: int the number of parameters required
        """
        count = 7
        for arg in sys.argv:
            if arg == "-g":
                count += 1
            if arg == "-r":
                count += 1
        return count

    def checkHost(self, host: str):
        """
        This function checks if the host is correct.

        @param host: str the host to check

        @return: True if the host is correct, False otherwise
        """

        if host == "localhost":
            return True

        host = host.split(".")
        if len(host) != 4:
            return False

        for i in host:
            if not i.isdigit():
                return False
            if int(i) < 0 or int(i) > 255:
                return False

        return True

    def checkParameters(self):
        """
        This function checks if the parameters are correct and if not, displays the help message.

        @return: 84 if the parameters are incorrect, 0 otherwise
        """
        try:
            if len(sys.argv) != self.nbOfParametersRequired():
                self.displayHelp()
                return 84

            if "-p" not in sys.argv or "-n" not in sys.argv or "-h" not in sys.argv:
                self.displayHelp()
                return 84

            for arg in sys.argv:
                if arg == "-p":
                    if not sys.argv[sys.argv.index(arg) + 1].isdigit():
                        print("The port must be a number.")
                        return 84
                    self.port = sys.argv[sys.argv.index(arg) + 1]
                if arg == "-h":
                    if not self.checkHost(str(sys.argv[sys.argv.index(arg) + 1])):
                        print("The host must be a ip or localhost.")
                        return 84
                    self.host = str(sys.argv[sys.argv.index(arg) + 1])
                if arg == "-n":
                    self.name = str(sys.argv[sys.argv.index(arg) + 1])
                if arg == "-g":
                    self.graphical = True
                if arg == "-r":
                    self.random = True

            if len(self.port) == 0 or len(self.host) == 0 or len(self.name) == 0:
                self.displayHelp()
                return 84
        except:
            self.displayHelp()
            return 84
