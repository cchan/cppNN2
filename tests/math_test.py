import unittest
import cppNN

a = cppNN.vec([1,2,3])
b = cppNN.vec([4,5,6])
c = cppNN.vec([5,7,9])
d = cppNN.vec([])
e = cppNN.vec([0,2,1])

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
    def test_getitem(self):
        self.assertEqual(a[2], 3)
        self.assertEqual(c[1], 7)
        with self.assertRaises(IndexError) as context:
          d[0]
        self.assertTrue(str(context.exception).startswith("vector::_M_range_check"))
    def test_indexing(self):
        #self.assertEqual((type(c), type(cppNN.vec([2,2,1]))), 0)
        self.assertEqual(c.idx([0,2,1]), cppNN.vec([5,9,7]))

if __name__ == '__main__':
    unittest.main()
