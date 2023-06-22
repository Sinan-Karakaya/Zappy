import unittest
import os
import sys
# import coverage
from unittest.mock import patch
from io import StringIO

current_dir = os.path.dirname(os.path.abspath(__file__))
parent_dir = os.path.dirname(current_dir)
sys.path.insert(0, parent_dir)

from src.Parameters.Parameters import Parameters

class TestRepetoile(unittest.TestCase):
    def setUp(self):
        self.parameters = Parameters()
    
    def testInit(self):
        self.assertEqual(self.parameters.port, "")
        self.assertEqual(self.parameters.host, "localhost")
        self.assertEqual(self.parameters.name, "")
        self.assertEqual(self.parameters.graphical, False)

    @patch('sys.stdout', new_callable = StringIO)
    def testHelp(self,stdout):
        self.parameters.displayHelp()
        self.assertEqual(stdout.getvalue(), "USAGE: ./zappy_ai -p port -n name -h machine\n\tport\tis the port number\n\tname\tis the name of the team\n\tmachine\tis the name of the machine; localhost by default\n")