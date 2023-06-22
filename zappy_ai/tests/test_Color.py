import unittest
import os
import sys
from unittest.mock import patch
from io import StringIO
# import coverage

current_dir = os.path.dirname(os.path.abspath(__file__))
parent_dir = os.path.dirname(current_dir)
sys.path.insert(0, parent_dir)


from src.Color.Color import OKGREEN, WARNING, OKCYAN, ENDC, coloredPrint

class testColor(unittest.TestCase):
    def setUp(self) -> None:
        ...
    
    @patch('sys.stdout', new_callable = StringIO)
    def testColoredPrint(self, stdout):
        coloredPrint("ok")
        self.assertEqual(stdout.getvalue(), OKGREEN + " | Receive: ok" + ENDC)

    @patch('sys.stdout', new_callable = StringIO)
    def testColoredPrint2(self, stdout):
        coloredPrint("ko")
        self.assertEqual(stdout.getvalue(), WARNING + " | Receive: ko" + ENDC)

    @patch('sys.stdout', new_callable = StringIO)
    def testColoredPrint3(self, stdout):
        coloredPrint("Otherwise")
        self.assertEqual(stdout.getvalue(), OKCYAN + " | Receive: Otherwise" + ENDC)
        

if __name__ == '__main__':
    unittest.main()