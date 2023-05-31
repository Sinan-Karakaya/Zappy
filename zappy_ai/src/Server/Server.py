##
## EPITECH PROJECT, 2023
## zappy_ai
## File description:
## Server
##

import socket


class Server:
    def __init__(self, ip, port):
        self.ip = ip
        self.port = port
        self.socket = None

    def connect(self):
        self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.socket.connect((self.ip, self.port))

    def printResponse(self):
        self.data = self.socket.recv(1024).decode("ASCII")
        print(self.data, end="")
    
    def getResponse(self):
        self.data = self.socket.recv(1024).decode("ASCII")
        return self.data
