#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "vectors.hpp"

namespace py = pybind11;

PYBIND11_PLUGIN(cppNN) {
  py::module m("cppNN", R"doc(
        Python module
        -----------------------
        .. currentmodule:: cppNN
        .. autosummary::
           :toctree: _generate

           add
           subtract
    )doc");

  m.def("vectorToString", &vectorToString<double>, R"doc(
        Convert a vector to a string.
    )doc");

  return m.ptr();
}
