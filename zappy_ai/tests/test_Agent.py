import unittest
import os
import sys
# import coverage

current_dir = os.path.dirname(os.path.abspath(__file__))
parent_dir = os.path.dirname(current_dir)
sys.path.insert(0, parent_dir)

from src.Agent.Agent import Agent
from src.Server.Server import Server


class TestAgent(unittest.TestCase):
    def setUp(self):
        self.server = Server("localhost", 4242)
        self.agent = Agent(self.server)
        # self.agent.server.connect()
        # self.agent.server.getResponse()
        # self.agent.server.socket.sendall(("Team1" + "\n").encode("ASCII"))
        # self.agent.server.printResponse()

    def testInit(self):
        self.assertEqual(self.agent.level, 0)
        self.assertEqual(self.agent.vision, [])
        self.assertEqual(self.agent.moveStack, [])

    def testTreatMessage(self):
        result = self.agent._Agent__treatMessage("message")
        self.assertEqual(result, False)

        result = self.agent._Agent__treatMessage("Elevation underway")
        self.assertEqual(result, False)

        with self.assertRaises(SystemExit) as cm:
            self.agent._Agent__treatMessage("dead")
        self.assertEqual(cm.exception.code, 0)
        
        result = self.agent._Agent__treatMessage("Otherwise")
        self.assertEqual(result, True)
    

    def testDistanceToGoRight(self):
        dist = self.agent.distanceTo(7)
        self.assertEqual(dist, 3)

        dist = self.agent.distanceTo(1)
        self.assertEqual(dist, 1)

        dist = self.agent.distanceTo(0)
        self.assertEqual(dist, 0)

    def testDistanceToGoLeft(self):
        dist = self.agent.distanceTo(4)
        self.assertEqual(dist, 4)

    def testFillMoveStack(self):
        self.agent.fillMoveStack(7)
        self.assertEqual(
            self.agent.moveStack, ["Forward", "Forward", "Right", "Forward"]
        )

    # def testFillMoveStackWithWrongArg(self):
    #     self.agent.fillMoveStack(0)
    #     self.assertEqual(self.agent.moveStack, [])

    # def testFillInventory(self):
    #     self.agent.fillInventory()
    #     self.assertTrue(self.agent.inventory["food"] > 0)

    # def testFillVisions(self):
    #     self.agent.fillVisions()
    #     self.assertTrue(len(self.agent.vision[0]) > 0)

    # def testCanNotElevateNoRessources(self):
    #     self.agent.fillVisions()
    #     self.assertTrue(len(self.agent.vision) > 0)
    #     self.assertFalse(self.agent.canElevate())

    # def testCanNotElevateNoVision(self):
    #     self.assertFalse(self.agent.canElevate())

    # def testCanNotElevateNotEnoughRessources(self):
    #     self.agent.level = 2
    #     self.agent.vision = [
    #         ["player", "linemate"],
    #         ["deraumere", "food", "food"],
    #         ["food", "food", "food"],
    #         ["food", "food"],
    #     ]
    #     self.assertFalse(self.agent.canElevate())

    # def testCanElevateWithNoVision(self):
    #     self.assertFalse(self.agent.canElevate())

    # def testElevate(self):
    #     self.agent.inventory["linemate"] = 25
    #     self.agent.inventory["food"] = 25
    #     self.agent.elevate()

    # def testSearchObject(self):
    #     self.agent.searchObject("player")
    #     self.agent.searchObject("deraumere")
    #     self.agent.searchObject("linemate")

    # def testWrongIndex(self):
    #     self.assertFalse(self.agent.distanceTo(0))

    # def tearDown(self):
    #     self.agent.server.socket.close()


if __name__ == "__main__":
    # cov = coverage.Coverage()
    # cov.start()
    unittest.main()
    
    # cov.stop()
    # cov.report()