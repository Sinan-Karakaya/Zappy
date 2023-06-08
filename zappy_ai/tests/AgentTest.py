import unittest
import sys

sys.path.append("/home/noe/Travail/YEAR_PROJECT/Zappy/zappy_ai/")

from src.Agent.Agent import Agent
from src.Server.Server import Server


class TestAgent(unittest.TestCase):
    def setUp(self):
        self.agent = Agent(Server("localhost", 4242))
        self.agent.server.connect()
        self.agent.server.getResponse()

    def testDistanceToGoRight(self):
        dist = self.agent.distanceTo(7)
        self.assertEqual(dist, 3)

    def testDistanceToGoLeft(self):
        dist = self.agent.distanceTo(4)
        self.assertEqual(dist, 4)

    def testFillMoveStack(self):
        self.agent.fillMoveStack(7)
        self.assertEqual(
            self.agent.moveStack, ["Forward", "Forward", "Right", "Forward"]
        )

    def testFillMoveStackWithWrongArg(self):
        self.agent.fillMoveStack(0)
        self.assertEqual(self.agent.moveStack, [])

    def testFillInventory(self):
        self.agent.fillInventory()
        self.assertTrue(len(self.agent.inventory) > 0)

    def testFillVisions(self):
        self.agent.fillVisions()
        self.assertTrue(len(self.agent.vision) > 0)

    def testCanNotElevateNoRessources(self):
        self.agent.fillVisions()
        self.assertTrue(len(self.agent.vision) > 0)
        self.assertFalse(self.agent.canElevate())

    def testCanNotElevateNoVision(self):
        self.assertFalse(self.agent.canElevate())

    def testCanNotElevateNotEnoughRessources(self):
        self.agent.level = 2
        self.agent.vision = [
            ["player", "linemate"],
            ["deraumere", "food", "food"],
            ["food", "food", "food"],
            ["food", "food"],
        ]
        self.assertFalse(self.agent.canElevate())

    def testCanElevateWithNoVision(self):
        self.assertFalse(self.agent.canElevate())

    def testWrongIndex(self):
        self.assertFalse(self.agent.distanceTo(0))

    def tearDown(self):
        self.agent.server.socket.close()


if __name__ == "__main__":
    unittest.main()
