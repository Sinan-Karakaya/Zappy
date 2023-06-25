##
## EPITECH PROJECT, 2023
## zappy_ai
## File description:
## Server
##

import socket


class Server:
    def __init__(self, ip: str, port: int):
        self.ip = ip
        self.port = port
        self.socket = None

    def connect(self):
        """
        Connect client to the server and init the socket.
        """
        self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        try:
            connect = self.socket.connect((self.ip, self.port))
        except:
            print("Error: Can't connect to the server.")
            exit(84)

    def getResponse(self):
        """
        Get the response from the server, set the data and return the response.
        """
        self.data = self.socket.recv(2048).decode("ASCII")
        return self.data

    def printResponse(self):
        """
        Display the response from the server and set the data.
        """
        print(self.getResponse(), end="")
