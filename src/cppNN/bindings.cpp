#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/operators.h>
#include "vectors.hpp"

namespace py = pybind11;

using namespace cppNN;

PYBIND11_MODULE(cppNN, m) {  
  py::class_<vec<double>>(m, "vector")
      .def(py::init<const vec<double> &>())
      .def(py::init<const std::vector<double> &>())
      .def("__repr__", &vec<double>::toString)
      .def(py::self + py::self)
      // .def(py::self += py::self)
      .def(py::self - py::self)
      // .def(py::self -= py::self)
      // .def(py::self + double())
      // .def(py::self += double())
      // .def(py::self - double())
      // .def(py::self -= double())
      // .def(py::self * double())
      // .def(py::self *= double())
      // .def(py::self / double())
      // .def(py::self /= double())
      .def(- py::self)
      // .def(py::self == py::self)
      .def("dot", (double(vec<double>::*)(const vec<double>&)const) &vec<double>::dot)
      // .def("mul", &vec<double>::mul)
      .def("__getitem__", (vec<double>::const_reference(vec<double>::*)(vec<double>::size_type)const) &vec<double>::at)
      .def("__setitem__", &vec<double>::set)
      .def("__eq__", (bool(vec<double>::*)(const vec<double>&)const) &vec<double>::operator==)
      // .def("at", &std::vector<double>::at)
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
