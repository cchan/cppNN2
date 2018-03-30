import unittest
import cppNN

class MainTest(unittest.TestCase):
    def test_vectorToString(self):
        self.assertEqual(cppNN.vectorToString([1,2,3]), "{1,2,3}")

if __name__ == '__main__':
    unittest.main()
