import unittest
import cppNN

a = cppNN.vector([1,2,3])
b = cppNN.vector([4,5,6])
c = cppNN.vector([5,7,9])

class MainTest(unittest.TestCase):
    def test_vectorToString(self):
        self.assertEqual(repr(a), "{1,2,3}")
    def test_vectorAdd(self):
        self.assertEqual(a + b, c)
    def test_vectorSubtractNegate(self):
        self.assertEqual(b - c, - a)
    def test_dot(self):
        self.assertEqual(a.dot(b), 32)
        self.assertEqual(b.dot(c), 109)
        self.assertEqual(c.dot(a), 46)

if __name__ == '__main__':
    unittest.main()
