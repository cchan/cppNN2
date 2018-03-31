import unittest
import cppNN

a = cppNN.vector([1,2,3])
b = cppNN.vector([4,5,6])
c = cppNN.vector([5,7,9])
d = cppNN.vector([])

class MainTest(unittest.TestCase):
    def test_vectorToString(self):
        self.assertEqual(repr(a), "{1,2,3}")
        self.assertEqual(repr(d), "{}")
    def test_vectorAdd(self):
        self.assertEqual(a + b, c)
    def test_vectorSubtractNegate(self):
        self.assertEqual(b - c, - a)
    def test_dot(self):
        self.assertEqual(a.dot(b), 32)
        self.assertEqual(b.dot(c), 109)
        self.assertEqual(c.dot(a), 46)
    def test_exception(self):
        with self.assertRaises(ValueError) as context:
          a + d
        self.assertEqual(str(context.exception), "vec size mismatch")

if __name__ == '__main__':
    unittest.main()
