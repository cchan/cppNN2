# cppNN2

[![Build Status](https://travis-ci.org/cchan/cppNN2.svg?branch=master)](https://travis-ci.org/cchan/cppNN2)

Neural networks in C++ with Python bindings. Successor to [cppNN](https://github.com/cchan/cppNN).
Note that everything here except this title is called `cppNN`.


# Build

To build and test `cppNN`, clone this repository and then run:

```bash
git submodule update --init --recursive
python3 ./setup.py test
```


# Requirements

- Python 2 or 3
- CMake 2.8.12 or higher (probably)
- A modern compiler with C++11 support


# References

This code uses https://github.com/benjaminjack/python_cpp_example as a Python binding template.
