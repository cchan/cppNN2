# cppNN

Neural networks in C++ with Python bindings.

# Installation

To build and install `cppNN`, clone or download this repository and then, from within the repository, run:

```bash
git submodule update --init --recursive
```

and then


```bash
python3 ./setup.py install
```

or

```bash
pip3 install .
```

In case you're only interested in building/testing things from whitin the same directory, you could run:

```bash
python3 ./setup.py build
```

# Tests

To execute all unit tests, run the following command:

```bash
python3 ./setup.py test
```

# Requirements

- Python 2 or 3
- CMake 2.8.12 or higher
- A modern compiler with C++11 support

# Acknowledgements

This code uses https://github.com/benjaminjack/python_cpp_example as a template.
