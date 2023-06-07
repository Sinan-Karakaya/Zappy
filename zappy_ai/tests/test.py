import unittest
import sys

sys.path.append("/home/noe/Travail/YEAR_PROJECT/Zappy/zappy_ai/")

from src.Parameters.Parameters import Parameters
from src.Server.Server import Server


class TestParameters(unittest.TestCase):
    def setUp(self):
        self.param = Parameters()

    def test_check_parameters(self):
        self.assertTrue(self.param.checkParameters() == 84)
        self.assertFalse(self.param.host)
        self.assertFalse(self.param.port)
        self.assertFalse(self.param.name)


if __name__ == "__main__":
    unittest.main()
