import unittest
import sys

sys.path.append("/home/noe/Travail/YEAR_PROJECT/Zappy/zappy_ai/")

from src.Server.Server import Server


class TestServer(unittest.TestCase):
    def setUp(self):
        self.server = Server("localhost", 4242)
        self.server.connect()

    def testPrintResponse(self):
        self.server.printResponse()

    def tearDown(self):
        self.server.socket.close()


if __name__ == "__main__":
    unittest.main()
