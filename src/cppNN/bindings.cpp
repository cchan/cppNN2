#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/operators.h>
#include "vectors.hpp"

namespace py = pybind11;

PYBIND11_MODULE(cppNN, m) {  
  py::class_<cppNN::vec<double>>(m, "vector")
      .def(py::init<const cppNN::vec<double> &>())
      .def(py::init<const std::vector<double> &>())
      .def(py::self + py::self)
      .def(py::self += py::self)
      .def(py::self - py::self)
      .def(py::self -= py::self)
      .def(- py::self)
      .def(py::self == py::self)
      //.def(py::self * py::self)
      //.def(py::self *= py::self)
      //.def(double() * py::self)
      //.def(py::self * double())
      .def("dot", &cppNN::vec<double>::dot)
      .def("__repr__", &cppNN::vec<double>::toString)
      ;

  m.doc() = R"doc(
        Python module
        -----------------------
        .. currentmodule:: cppNN
        .. autosummary::
           :toctree: _generate

           add
           subtract
    )doc";

  //m.def("vectorToString", &vectorToString<double>, R"doc(
  //      Convert a vector to a string.
  //  )doc");
}
