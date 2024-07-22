#include <pybind11/pybind11.h>
#include "mpi_example.h"

namespace py = pybind11;

PYBIND11_MODULE(_core, m) {
    m.def("mpi_hello_world", &mpi_hello_world, "A function that prints Hello World from MPI ranks.");
}
