#include <pybind11/pybind11.h>
#include "main.h"

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

namespace container {

    namespace py = pybind11;

    PYBIND11_MODULE(cmake_example, m
    ) {
    bind_linkedlist(m);
    bind_map(m);
    bind_tree(m);

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}

}