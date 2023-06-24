import unittest
import os
import sys

# import coverage

current_dir = os.path.dirname(os.path.abspath(__file__))
parent_dir = os.path.dirname(current_dir)
sys.path.insert(0, parent_dir)

from src.Repetoile.Repetoile import Repetoile
from src.Server.Server import Server


class TestRepetoile(unittest.TestCase):
    def setUp(self):
        self.server = Server("localhost", 4242)
        self.agent = Repetoile("Tim", self.server)

    def testInit(self):
        self.assertEqual(self.agent.teamName, "Tim")
        self.assertEqual(self.agent.state, "Searching food")
